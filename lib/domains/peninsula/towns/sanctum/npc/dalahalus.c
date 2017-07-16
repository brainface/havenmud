#include <lib.h>
#include "../rome.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetReligion("Kylin");
  SetTown("Sanctum");
  SetKeyName("matathan");
  SetShort("Matathan, High Priest of Kylin");
  SetGender("male");
  SetClass("priest");
  SetLevel(80);
  SetCurrency("imperials", 200);
  SetMorality(1500);
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetUniqueSkills( ([
    ]) );
  SetLong("Matathan of Sanctum, High Priest of Kylin, is one of the most "
          "influential citizens of the Empire. His rock-solid willpower is "
          "often enough to decide an issue before the Imperial Senate, and "
          "his religion, which preaches nothing but Order in the Empire, "
          "is often supported by the Senate over the other religions.");
  SetSpellBook( ([
    "wall of force" : 100,
    "kylin touch"   : 100,
    ]) );
  SetAction(5, ({
    "!cast wall of force",
    "!speak Glory is obtained through bringing Order from Chaos!",
    "!speak Truth is discovered through Order.",
    "!speak Convert to the Order of Kylin!",
    "!speak My acolyte will be happy to convert you!",
    }) );
  SetCombatAction(40, ({
    "!cast wall of force",
    "!cast kylin touch",
    }) );
  SetInventory( ([
  	"/std/weapon/blunt/iron_mace" : "wield mace",
  	]) );
  SetLimit(1);
}
