// occurs at sailing > 120
// Mahkefel 2011 or so--made level to target.

#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetKeyName("viking captain");
  SetShort("a viking captain (goden)");
  SetId( ({ "captain", "viking", "goden" }) );
  SetAdjectives( ({ "viking", "goden" }) );
  SetRace("goden");
  SetTown("Keryth");
  SetClass("viking");
  SetLevel(60);
  SetLong(
    "This goden is a fierce killer, sailing the seas looking for plunder."
    );
  SetGender("female");
  SetCaptainAggressiveness(80);
  SetShipWander(1);
  SetCurrency("senones", 20000);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/broad_axe" :2,
    INNERSEA_ENCOUNTERS "obj/horned_helmet" : "wear helm",
  ]) );
  SetFirstCommands( ({ "wield all" }) );

  // lib pirate stuff.
  SetProperty("pirate","viking");
  SetEncounterDifficulty(5);
  SetMinLevel(60);
  SetMaxLevel(95);
  SetFirstMate(INNERSEA_ENCOUNTERS "viking/smallboarder");
}

