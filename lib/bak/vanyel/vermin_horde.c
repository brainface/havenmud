//
// Summon vermin horde
// by Ranquest@Haven
// A Natural Evokation spell
// started 5th December 1998
//
#include <lib.h>
#include <magic.h>
#define RAT "/std/spells/obj/rat"
inherit LIB_SPELL;
void RatKill(object target);

static void create() {
  spell::create();
  SetSpell("vermin horde");
  SetRules("","LIV");
  SetStaminaCost(40, 40);
  SetMagicCost(25, 25);
  SetDifficulty(15);
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "natural magic" : 5,
    ]) );
  SetHelp("Summons a horde of rats to attack the designated target.\n"
          "Once the target is dead, the rats vanish.");
  }

varargs int eventCast(object who,int level, mixed n, object *targets) {
  object target = targets[0];
  int rats;
  int i;
  foreach (object ob in filter(all_inventory(environment(who)), 
               (: (int)$1->is_living() :) )) {
    if (ob->GetKeyName() == "rat") {
      who->eventPrint("There are already too many animals in the area!");
      return 1;
    }
  }
  rats = 1 + level/3;
  rats += who->GetSkillLevel("natural magic")/20;
  if(rats > 15) rats = 10+random(5);
  send_messages("summon", 
    "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a horde of rats "
    "to attack $target_name!",
    who, target, environment(who) );
  for (i = 0;i<rats;i++) {
    RatKill(target);
    }
  return 1;
  }

void RatKill(object target) {
  object ratfetish;
  ratfetish = new(RAT);
  ratfetish->eventMove(environment(target));
  ratfetish->SetAttack(target);
  }
