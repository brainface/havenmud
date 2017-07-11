#include <lib.h>
#include <domains.h>
#include "../tairi.h"
inherit LIB_FERRYCAPTAIN;

static void create() {
  ::create();
  SetKeyName("ferry captain");
  SetLimit(3);
  SetShort("a leathered ferry boat captain");
  SetId( ({ "ferrycaptain", "captain" }) );
  SetAdjectives( ({ "leathered", "ferry", "boat" }) );
  SetRace("human");
  SetClass("sailor");
  SetBaseLanguage("Tai");
  SetLevel(80);
  SetMorality(10);
  SetGender("female");
  SetLong(
    "The ferry captain looks like shes been sailing the seas for quite some "
    "time, with her leathered skin and air of slightly annoyed competence.");
  SetShipWanderPath(TAIRI_TOWNS "tairi/room/path11", 
    HAVENWOOD_TOWNS "parva/room/docks1");
  SetAction( 10, ({
    "!say The journey to Parva is treacherous!",
    "!say the waters of the Endless Sea are unforgiving!",
    "!say Tie yourself down boys, we're in for some chop!",
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

