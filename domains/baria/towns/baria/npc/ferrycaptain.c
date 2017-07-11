#include <lib.h>
#include <domains.h>
#include "../jungle.h"
inherit LIB_FERRYCAPTAIN;

static void create() {
  ::create();
  SetKeyName("native ferryboatman");
  SetLimit(1);
  SetShort("a native ferryboatman");
  SetId( ({ "ferryboatman", "native", "man" }) );
  SetAdjectives( ({ "ferry", "boat", "native" }) );
  SetRace("human");
  SetBaseLanguage("Barian");
  SetClass("sailor");
  SetLevel(45);
  SetMorality(10);
  SetGender("male");
  SetLong("The ferry boat captain looks perfectly bored in his work.  So bored that "
          "sympathy for him comes fast and hard to anyone who views his plight.");
  SetShipWanderPath(BARIA_TOWNS "baria/room/path12", ISLANDS_AREAS "monkey/room/port");
  SetInventory( ([
    BARIA_OBJ + "spear" : "wield spear",
    BARIA_OBJ +"loincloth" : "wear loincloth",
  ]) );
  SetFirstCommands( ({
    "out",
    "board outrigger"
  }) );
  SetAction(10, ({ "!board first outrigger" }) );

}

