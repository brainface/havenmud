#include <lib.h>
#include <damage_types.h>
#include "../keryth.h"

inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("ziona");
  SetGender("female");
  SetLong("Ziona's gaze pierces through all she surveys.  Her dark eyes "
          "could penetrate into the very soul and read one's hopes, dreams, "
          "passions, and fears like an open book.  Her long fingernails "
          "look razor sharp and she appears disappointed with her "
          "surroundings, as if she wanted to be something other than a "
          "healer.");
  SetShort("Ziona the Healer");
  SetRace("goden");
  SetId( ({ "ziona", "healer" }) );
  SetReligion("Soirin", "Soirin");
  SetTown("Keryth");
  SetClass("cleric");
  SetCurrency("senones", random(80)+40);
  SetLocalCurrency("senones");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
  SetMeleeDamageType(SLASH);
  SetSkill("melee attack", 20, 1);
  SetLevel(10 + random(11));
  SetInventory( ([
    K_OBJ + "/common_pants" : "wear pants"
  ]) );
  SetMorality(50);
}
