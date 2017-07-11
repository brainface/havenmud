#include <lib.h>     
#include <domains.h> 
#include "../tairi.h"
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("ferry captain");
  SetLimit(3);
  SetShort("a ferry boat captain");
  SetId( ({ "ferrycaptain", "captain" }) );
  SetAdjectives( ({ "ferry", "boat" }) );
  SetRace("human");
  SetClass("sailor");
  SetBaseLanguage("Tai");
  SetLevel(80);
  SetMorality(10);
  SetGender("male");
  SetLong("The ferry boat captain looks perfectly bored in his work.  So bored that "
          "sympathy for him comes fast and hard to anyone who views his plight.");
  SetShipWanderPath(TAIRI_TOWNS "tairi/room/path11", HAVENWOOD_TOWNS "parva/room/docks1");
  SetAction( 10, ({
    "!say The journey to Parva is treacherous!",
    "!say the waters of the Endless Sea are unforgiving!",
  }) );
  SetFirstCommands( ({
    "out",
    "board ferry",
    "yell All Aboard!",
  }) );
  SetInventory( ([
    TAI_RI_OBJ "cotton_pants.c" : "wear trousers",
    TAI_RI_OBJ "plain_tanto" : "wield tanto",
    TAI_RI_OBJ "straw_hat" : "wear hat",
  ]) );
  SetAction(10, ({ "!board first ferry" }) );
}

