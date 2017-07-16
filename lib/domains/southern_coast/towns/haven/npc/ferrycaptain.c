#include <lib.h>
#include <domains.h>
#include "../haven.h"
inherit LIB_FERRYCAPTAIN;

static void create() {
  ::create();
  SetKeyName("ferry captain");
  SetLimit(1);
  SetShort("a ferry boat captain");
  SetId( ({ "ferrycaptain", "captain" }) );
  SetAdjectives( ({ "ferry", "boat" }) );
  SetRace("elf");
  SetClass("sailor");
  SetClass("fighter"); // change from cavalier, multiclass unavailable
  SetLevel(60);
  SetMorality(10);
  SetGender("male");
  SetLong("The ferry boat captain looks perfectly bored in his work.  So bored that "
          "sympathy for him comes fast and hard to anyone who views his plight.");
  SetShipWanderPath(AVERATH_TOWNS "averath/room/wharf", SOUTHERN_COAST_TOWNS "haven/room/wharf");
  SetFirstCommands( ({
    "out",
    "yell All aboard!",
"board first ferry",
  }));

  SetAction(10, ({ "!board first ferry" }) );
  SetInventory( ([
    H_OBJ "ferry_hat" : "wear hat",
    H_OBJ "ferry_jacket" : "wear jacket",
    H_OBJ "ferry_pants" : "wear trousers",
    H_OBJ "rapier" : "wield rapier",
  ]) );
}

