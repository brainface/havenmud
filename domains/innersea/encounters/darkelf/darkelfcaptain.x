// mahkefel 20101117: gave important piece of armour
#include <lib.h>
#include <domains.h>
#include <std.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetKeyName("dark elven captain");
  SetShort("a dark elven pirate captain");
  SetId( ({ "captain", "elf", "pirate" }) );
  SetAdjectives( ({ "dark", "pirate", "elven", "elf" }) );
  SetRace("dark-elf");
  SetTown("Malveillant");
  SetReligion("Soirin");
  SetClass("rogue");
  SetClass("sailor");
  SetLevel(20);
  SetLong(
    "This pirate sails from Parva, a home to thieves and other ne'er-do-wells."
  );
  SetGender("male");
  SetCaptainAggressiveness(80);
  SetShipWander(1);
  SetCurrency("roni", 20000);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/eyepatch_silk" : "wear eyepatch",
  ]) );
  SetMinLevel(20);
  SetMaxLevel(40);
  SetEncounterDifficulty(-3); // easier on nubs
}

