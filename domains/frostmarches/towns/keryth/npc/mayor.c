#include <lib.h>
#include <damage_types.h>
#include "../keryth.h"

inherit LIB_MAYOR;

static void create() {
  ::create();
  SetShort("Pharez, Mayor of Keryth");
  SetId( ({ "pharez", "mayor" }) );
  SetAdjectives( ({ "large", "tall", "angry", "intimidating" }) );
  SetKeyName("pharez");
  SetRace("goden");
  SetLocalCurrency("senones");
  SetTax(100);
  SetTown("Keryth");
  SetMorality(-50);
  SetClass("fighter");
  SetLevel(60);
   SetCurrency("senones", random(260)+250);
  SetAction(2, ({
    "!speak If you wish to become a citizen, I am the man to talk to.",
    "!growl angrily"
  }) );
  SetCombatAction(50, ({
    "!disarm",
    "!scream sadist",
    "!muah",
    "!disorient",
    "!yell I'll tear you to bloody shreds!",
    "!speak DIE!!!"
  }) );
  SetLong("Flaming, repressed rage fills the eyes of this sturdy Goden.  A "
          "truly intimidating presence, Pharez radiates power and appears "
          "ready to mercilessly slaughter any opposition; however, "
          "requesting citizenship should not prove to be a dangerous "
          "affair.");
  SetGender("male");
  SetMeleeDamageType(SLASH);
  SetInventory( ([
    K_OBJ + "/mayor_pants" : "wear pants",
    K_OBJ + "/battle_axe"  : "wield axe",
  ]) );
}
