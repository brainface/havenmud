#include <lib.h>
#include <magic.h>
#include <daemons.h>
inherit LIB_SPELL;

void ProcessTarget(string town, object who);
void CheckTown(string town, object who);

static void create() {
  ::create();
  SetSpell("instantaneous movement");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(200, 600);
  SetDifficulty(40);
  SetSkills( ([
    "enchantment" : 400,
    "conjuring"   : 400,
    ]) );
  SetHelp(
    "Use of instantaneous movement can be the most powerful tool of the enchanter. "
    "This spell allows movement unrestricted by time or space, by simply thinking "
    "of a city settled by sentient creatures. Upon success, the caster is transported "
    "to the target location. An invalid choice of destination will drain the cast of all their magic points."
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
  
  send_messages( ({ "focus" }),
    "$agent_name $agent_verb $agent_possessive concentration for a brief moment...",
    caster, 0, environment(caster) );
  caster->eventPrint("%^BOLD%^RED%^Think about which city? (Options: " + conjunction(SETUP_D->GetAllTowns(), "or") + "): ");
  input_to( (: CheckTown :), caster );
  return 1;
}

void CheckTown(string town, object who) {
   object env  = environment(who);
   object envT; 
   int distance;
   string *towns = SETUP_D->GetAllTowns();
   string tmp;
  
   tmp = capitalize(town); 
   envT = SETUP_D->GetStartRoom(tmp);
   
  if (member_array(tmp, towns) == -1) {
    who->eventPrint("That (" + town + ") does not seem to be a valid town!");
     who->AddMagicPoints(-who->GetMagicPoints());
    return;   
  }
    distance = DISTANCE_D->GetDistance(env->GetDomain(), envT->GetDomain());
    SetDifficulty(75 * (1 + distance));
    return ProcessTarget(tmp, who);
}

void ProcessTarget(string tmp, object who) {
    int *failure = ({ 0, 0 });
    int fc = 0;
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
  who->eventMoveLiving(SETUP_D->GetStartRoom(tmp), "$N disappears in a flash of light.", "$N materializes from thin air!");
  who->eventPrint("You focus your energies and move yourself to " + tmp + ".");
  return;
}

