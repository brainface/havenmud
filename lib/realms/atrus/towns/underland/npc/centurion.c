#include <lib.h>
#include "../underland.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("centurion");
  SetRace("elemental");
  AddFingers(4);
  //RemoveLimb("left hand", 0);
  SetGender("male");
  SetShort("an underland centurion");
  SetId( ({ "centurion", "wanderer", "elemental" }) );
  SetAdjectives( ({ "green", "underland" }) );
  SetLong(
    "This startling elemental is made completely of energy. The "
    "flesh of this thing is writhing with psionic energies which swirl "
    "with his every move. His armour floats amongst the dancing "
    "energies and seems to pulsate with power of their own. Surely this "
    "charmed being is not one to be triffled with. He has no legs, only "
    "a twisted mist of energies that seem to carry him forth."
    );
  SetClass("fighter");
  SetClass("priest");
  SetSkill("pole combat", 1, 1);
  SetLevel(255);
  SetInventory( ([
    UNDER_OBJ "elegaunt1" : "wear a gauntlet on right hand",
    UNDER_OBJ "elesword"    : "wield sword",
    UNDER_OBJ "elegaunt2" : "wear a gauntlet on left hand",
    UNDER_OBJ "eleplate" : "wear breastplate",
    UNDER_OBJ "elehelm" : "wear helmet",
    UNDER_OBJ "elering" : "wear ring on left hand",
    ]) );
  SetTown("Underland");
  SetCurrency("rupies", 1000);
  SetWander(8);
  SetSpellBook( ([
    "avalanche"          : 100,
    "soul taint"         : 100,
    "maddening visions"  : 100,
    "cause bleeding"     : 100,
    "flamestrike"        : 100,
    "curse"              : 100,
    "unholy guardian"    : 100,
    "touch of death"     : 100,
    "temperature shield" : 100,
    ]) );
  SetCombatAction(50, ({
    "!cast maddening visions",
    "!cast soul taint",
    "!cast cause bleeding",
    "!cast curse",
    "!cast touch of death",
    "!cackle",
    "!cast soul tap",
    "!cast flamestrike",
    "!cast avalanche",
    }) );
  SetMorality(-500);
  SetCurrency("crystals", 5000);
  SetFirstCommands( ({ 
    "cast temperature shield",
    "cast temperature shield",
    "cast unholy guardian",
    "cast unholy guardian",
    "cast unholy guardian",
  }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 2) {
    eventForce("unholy guardian");

  }
}
