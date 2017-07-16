// mahkefel 2012: cheap copy of dark elf caravel dude
#include <lib.h>
#include <domains.h>
#include <std.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetKeyName("elven lieutenant");
  SetShort("an elven lieutenant");
  SetId( ({ "lieutenant", "elf" }) );
  SetAdjectives( ({ "elven", "elf" }) );
  SetRace("elf");

  SetTown("Haven");
  SetReligion("Kylin");
  SetProperty("pirate","haven");

  SetClass("rogue");
  SetClass("sailor");
  SetLevel(20);
  SetLong(
    "This naval officer sails from Haven, and defends her "
    "port city with great zeal."
  );
  SetGender("female");
  SetCaptainAggressiveness(50);
  SetShipWander(1);
  SetCurrency("imperials", 20000);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/haven_jacket" : "wear jacket",
    INNERSEA_ENCOUNTERS "obj/haven_pants" : "wear trousers",
    STD_PIERCE "rapier" : "wield rapier",
  ]) );
  SetMinLevel(20);
  SetMaxLevel(40);
  SetEncounterDifficulty(-2); // easier on nubs

  SetAction(5, ({
    "!say Have you seen any smugglers?",
    "!say Be on the lookout for pirates.",
  }) );

  SetCombatAction(10, ({
    "!say For the Lord of Order!",
    "!say You'll not stain Haven's shores!",
  }) );
  SetFirstMate(INNERSEA_ENCOUNTERS "elfsloop/steam");
}

