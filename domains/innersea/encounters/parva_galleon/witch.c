// mahkefel 2012: cheap copy of dark elf caravel dude
#include <lib.h>
#include <domains.h>
#include <std.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetKeyName("sea witch");
  SetShort("a sea witch (half elf)");
  SetId( ({ "witch","half elf" }) );
  SetAdjectives( ({ "sea","half","elf" }) );
  SetRace("half-elf");

  SetTown("Parva");
  SetReligion("Thorian");
  SetProperty("pirate","parva");

  SetClass("necromancer");
  SetSkill("sailing",1);
  SetSkill("swimming",1);
  SetSkill("navigation",1);

  SetLevel(75);
  SetLong(
    "This solemn woman's face and arms are covered in elaborate tatoos. "
    "The dark tint of her skin belies a malviellant ancestry, and glimmering "
    "corpusants dance over her head."
  );
  SetGender("female");
  SetCaptainAggressiveness(50);

  SetCurrency("imperials", 20000);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/jeweled_dagger" : "wield dagger",
  ]) );
  SetMinLevel(75);
  SetMaxLevel(125);
  SetEncounterDifficulty(0); // easier on nubs

  SetAction(5, ({
    "!say Fear death by water.",
    "!grumble",
    "!say The Unnamed One's reach is long.",
  }) );

  SetCombatAction(25, ({
    "!cast poison orbs",
    "!cast soultap",
    "!say Decayed One take ye!",
  }) );

  SetFirstMate(INNERSEA_ENCOUNTERS "/elemental_water/brine");
}

void heart_beat() {
  object ship;

  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
      eventForce("cast veil from beyond");
  }

  ship = environment();

  // if I am on a ship, that is mine, and i'm fighting a ship.
  if(vehiclep(ship) 
    && ship->GetPilot() == this_object()
    && ship->GetEnemies()) {

    if (!random(10)) {
      eventForce("cast steam flash");
    }
  }
}


