#include <lib.h>
#include <dirs.h>
#include <magic.h>
#define RAT DIR_SPELLS "/obj/vermin_horde_rat"
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("replication");
  SetRules("");
  SetDifficulty(15);
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "illusion" : 100,
    ]) );
  SetHelp("Makes more of you.");
}

varargs int eventCast(object who, int level, mixed n, object *targets) {
  //object target = targets[0];
  object replicant;
  int replicants;
  int illusion = who->GetSkillLevel("illusion");



  rats = 1 + level/5;
  if(rats > 8) rats = 8;
  send_messages("summon",
    "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a horde of rats to attack $target_name!",
    who, target, environment(who) );
  for (i = 0;i<rats;i++) {
    rat = new(RAT);
    rat->AddFriend(who->GetKeyName());
    rat->SetOwner(who->GetKeyName());
    rat->eventMove(environment(target));
    //rat->SetAttack(target);  /*Edited out so that all the rats don't die on spawn vs
                               /*larger creatures, also reduntant since AddFriend will
                               /*force the rats to attack    -Melchezidek 9/10/09  */
    }
  return 1;
}

