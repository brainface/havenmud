// Lizardman invasion of Lloryk
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../lmil.h"

inherit LIB_INVADER;

int invEncounter(object);

static void create() {
  ::create();
  SetKeyName("lizardman raider");
  SetShort("a lizardman raider");
  SetId( ({ "raider", "lizardman", "liz_inv" }) );
  SetAdjectives( ({ "lizardman", "murderous" }) );
  SetLong(
    "This lizardman seems intent on sacking the Shire and "
    "carrying away its riches. His demeanor is one of plunder "
    "and murder."
  );
  SetRace("lizardman");
  SetGender("male");
  SetEnemyTown("Lloryk");    
  SetClass("fighter");
  SetLevel(15);
  SetMorality(-200);
  SetInventory( ([
    LMIL_OBJ + "spear" : "wield spear",
  ]) );
  SetCurrency("rounds", 10);
  SetAction(10, ({ 
    "!yell Flee before me, halflings!",
    "!yell We're coming to end this foolishness, halflings!",
  }) );
  SetCombatAction(5, ({
    "!yell Kill them all!",
    "!yell Burn the town!",
  }) );
  SetFriends( ({ "liz_inv" }) );
  SetEncounter( (: invEncounter :) );
  SetWanderSpeed(2);
  SetWanderPath( ({
    "go east", "go east", "go east", "go east", "go east", "go east",
    "go north", "enter hall",
  }) );
}

int invEncounter(object ob) {
  if (ob->GetProperty("invader")) return 0;
   else { SetAttack(ob);
          AddEnemy(ob);
          return 1;
        }
}