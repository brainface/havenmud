
#include <lib.h>
#include "../durgoroth.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetKeyName("Ysrital");
  SetShort("Ysrital, Taigis' Chosen Champion of Durgoroth");
  SetId( ({ "ysrital", "mayor", "champion", "durg_nocombat",
            "durg_wander" }) );
  SetAdjectives( ({ "Taigis'", "daemon", "champion" }) );
  SetLong(
    "As the largest and most powerful daemon to remain"
    " in the city, Ysrital is the decider of who lives"
    " and dies. His fearsome appearance is magnified by"
    " his reputation as one of the most gruesome and"
    " vicious beings ever to walk upon Kailie. Anyone"
    " seeking refuge in the Ruins of Durgoroth must"
    " speak to Ysrital for permission."
  );
  SetRace("daemon");
  SetGender("male");
  SetClass("horror");
  SetLevel(250);
  SetTown("Durgoroth");
  SetMorality(-2500);
  SetInventory( ([
     DURG_OBJ "fighter_helmet" : "wear helmet",
     DURG_OBJ "fighter_plate"  : "wear suit",
     DURG_OBJ "horseshoe"      : "wear 1st horseshoe on left hoof",
     DURG_OBJ "horseshoe2"     : "wear 1st horseshoe on right hoof",
     DURG_OBJ "duster"         : "wield 1st duster",
     DURG_OBJ "duster2"        : "wield 1st duster",
    ]) );
  SetTax(50);
  SetWander(5);
  SetLocalCurrency("crystals");
  SetTownRanks( ({
    ({ "Slave", "Slave" }),
    ({ "Survivor", "Survivor" }),
    ({ "Terror", "Terror" }),
    ({ "Dread", "Dread" }),
    ({ "Fiend", "Fiend" }),
    ({ "Archfiend", "Archfiend" }),
    ({ "Devil", "Devil" }),
    }) );
  SetCombatAction(50, ({
    "!scream",
    "!disarm",
    "!disorient",
    "!scream",
  }) );
}
