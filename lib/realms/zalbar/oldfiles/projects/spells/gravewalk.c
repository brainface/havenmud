#include <lib.h>
#include <magic.h>
#include <daemons.h>
inherit LIB_SPELL;

void ProcessTarget(string town, object who);
void CheckTown(string town, object who);

static void create() {
  ::create();
  SetSpell("grave walk");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(200, 600);
  SetDifficulty(40);
  SetSkills( ([
    "conjuring"    : 300,
    "necromancy"   : 300,
    ]) );
  SetHelp(
   "This spell allows the advanced necromancer to move between the places of "
   "the dead all across the world. An invalid choice will drain the caster of all their magic."
    );
}

varargs int CanCast(object caster, int level, string u, object array targets) {
  object target = targets[0];
  object env = environment(caster);
 
  if (env->GetProperty("no teleport")) {
    caster->eventPrint("You cannot seem to flee this place.");
    return 0;
  }
  return ::CanCast(caster, level, u, targets);
}

varargs int eventCast(object caster, int level, string u, object array targets) {
  
  send_messages( ({ "chant" }),
    "$agent_name $agent_verb grimly... the echo of the words hang in the air for a moment...",
    caster, 0, environment(caster) );
  caster->eventPrint("%^BOLD%^RED%^Where would you like to go? "
  "(Options: " + conjunction(SETUP_D->GetAllTowns()) + ")" );
  input_to( (: CheckTown :), caster );
  return 1;
}

void CheckTown(string town, object who) {
   object env  = environment(who);
   object envT; 
   int distance;
   string tmp;
//   debug(town);
   tmp = capitalize(town); 
//   debug("t: " + town + " bn " + base_name(envT));
   
  if (member_array(tmp, SETUP_D->GetAllTowns() ) == -1) {
    who->eventPrint("That (" + town + ") does not seem to be a valid choice!");
      who->AddMagicPoints(-who->GetMagicPoints());
    send_messages( ({ "chant" }),
    "$agent_possessive_noun voice darkens to a whisper of evil.",
    who, 0, environment(who) );
    return;   
  }
    envT = load_object(SETUP_D->GetCemetery(tmp));
    distance = DISTANCE_D->GetDistance(env->GetDomain(), envT->GetDomain());
    SetDifficulty(75 * (1 + distance));
    return ProcessTarget(tmp, who);
}

void ProcessTarget(string tmp, object who) {
    int *failure = ({ 0, 0 });
    int fc = 0;
    object* followers;
    followers = who->GetFollowers();
    if(!followers) followers = ({});
    failure[0] = random(GetDifficulty());
    failure[0] = (failure[0] * 50) / (who->GetSpellLevel(GetSpell()));
    failure[0] += failure[0] * who->GetRecoveryTime(); 
    foreach(string skill in GetSkills()) {
            failure[0] -= (who->GetSkillLevel(skill) - GetRequiredSkill(skill)) * 5; 
      }
    if (failure[0] < 0) failure[0] = 0;
    failure[1] = random(100);
    if (failure[1]  < failure[0]) {
            fc = failure[0] - failure[1];
            if (fc > GetSpellLevel() * 4) fc = GetSpellLevel() * 4;
            eventFail(who, fc);
            eventTrainSpell(who, 0);
            return;
      }
  eventTrainSpell(who, 1);
  who->eventMoveLiving(SETUP_D->GetCemetery(tmp), "$N fades into a dark mist.", "$N appears from a dark mist!");
  followers->eventMoveLiving(SETUP_D->GetCemetery(tmp), "$N fades into a dark mist.", "$N appears from a dark mist!");
  who->eventPrint("You begin to chant the words to move you to " + tmp + " and your power carries you there.");
  return;
}

