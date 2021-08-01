//
// Summon vermin horde
// yet another copy of vermin horde
//
#include <lib.h>
#include <dirs.h>
#include <magic.h>
#define BAT DIR_SPELLS "/obj/fruit_bat"
inherit LIB_SPELL;
void RatKill(object target);

static void create() {
  spell::create();
  SetSpell("bat swarm");
  SetMagicCost(0,0);
  SetDrinkCost(50,25);
  SetRules("","LIV");
  SetDifficulty(15);
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "vampirism" : 5,
    ]) );
  SetHelp("Summons a swarm of bats to swoop around and assault your opponent.\n"
    );
}

varargs int eventCast(object who,int level, mixed n, object *targets) {
  object target = targets[0];
  object bat;
  int bats;
  int i;
  foreach (object ob in filter(all_inventory(environment(who)),
    (: (int)$1->is_living() :) )) {
    if (ob->GetKeyName() == "bat") {
      who->eventPrint("The bats here flap for themselves, not for you.");
      return 1;
    }
  }
  bats = 1 + level/5;
  if(bats > 8) bats = 8;
  send_messages("summon",
    "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a swarm of bats to attack $target_name!",
    who, target, environment(who) );
  for (i = 0;i<bats;i++) {
    bat = new(BAT);
    bat->AddFriend(who->GetKeyName());
    bat->SetOwner(who->GetKeyName());
    bat->eventMove(environment(target));
    }
  return 1;
}

