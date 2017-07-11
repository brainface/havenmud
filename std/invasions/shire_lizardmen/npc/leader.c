// Lizardman invasion of Lloryk
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include <rooms.h>
#include "../lmil.h"

inherit LIB_INVADER;

int invEncounter(object);

static void create() {
  ::create();
  SetKeyName("lizardman chieftain");
  SetShort("a large lizardman chieftain");
  SetId( ({ "chieftain", "lizardman", "chief", "liz_inv" }) );
  SetAdjectives( ({ "large", "murderous", "lizardman" }) );
  SetLong(
    "This large lizardman seems intent on sacking the Shire and "
    "carrying away its riches. His demeanor is one of plunder "
    "and murder."
  );
  SetRace("lizardman");
  SetEnemyTown("Lloryk");    
  SetGender("male");
  SetClass("fighter");
  SetLevel(25);
  SetMorality(-200);
  SetInventory( ([
    LMIL_OBJ + "spear" : "wield spear",
  ]) );
  SetCurrency("rounds", 100);
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
  if (base_name(ob) == CRYSTAL_REACHES_TOWNS "lloryk/npc/guard") {
    ob->eventForce("emote flees from the lizardman hordes!");
    ob->eventMove(ROOM_VOID);
    ob->eventDestruct();
    return 1;
  }
  if (ob->GetProperty("invader")) return 0;
   else { SetAttack(ob);
          AddEnemy(ob);
          return 1;
        }
}