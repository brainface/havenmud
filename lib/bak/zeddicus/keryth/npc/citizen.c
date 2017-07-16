#include <lib.h>
#include "../keryth.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetProperty("KerythWander", 1);
  SetCurrency("senones", random(26)+25);
  SetShort("a citizen of Keryth");
  SetId( ({ "citizen" }) );
  SetRace("goden");
  SetClass("hunter");
  SetLevel(5 + random(6));
  SetGender(random(2) ? "male" : "female");
  SetLong("This citizen of Keryth strolls casually through town, as if " +
          nominative(this_object()) + " has nothing better to do.");
  SetWander(5);
  SetInventory( ([
    K_OBJ + "/common_pants" : "wear pants"
  ]) );
  SetMorality(-2000 + random(4001));
}
