//
// Summon vermin horde
// by Ranquest@Haven
// A Natural Evokation spell
// started 5th December 1998
//
#include <lib.h>
#include <dirs.h>
#include <magic.h>
#define RAT DIR_SPELLS "/obj/vermin_horde_rat"
inherit LIB_SPELL;
void RatKill(object target);

static void create() {
  spell::create();
  SetSpell("vermin horde");
  SetRules("","LIV");
  SetDifficulty(15);
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "natural magic" : 5,
     "evokation"     : 5,
    ]) );
  SetHelp("Summons a horde of rats to attack the designated target.\n"
          "Once the target is dead, the rats vanish.");
}

varargs int eventCast(object who,int level, mixed n, object *targets) {
  object target = targets[0];
  object rat;
  int rats;
  int i;
  foreach (object ob in filter(all_inventory(environment(who)), 
               (: (int)$1->is_living() :) )) {
    if (ob->GetKeyName() == "rat") {
      who->eventPrint("There are already too many animals in the area!");
      return 1;
    }
  }
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
//    rat->SetAttack(target);  /*Edited out so that all the rats don't die on spawn vs
                               /*larger creatures, also reduntant since AddFriend will
                               /*force the rats to attack    -Melchezidek 9/10/09  */
    }
  return 1;
}
