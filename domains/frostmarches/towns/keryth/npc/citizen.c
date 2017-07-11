#include <lib.h>
#include "../keryth.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetProperty("KerythWander", 1);
  SetShort("a citizen of Keryth");
  SetId( ({ "citizen" }) );
  SetRace("goden");
  SetClass("rogue");
  SetLevel(5 + random(6));
  SetCurrency("senones", random(20)+8);
  SetGender(random(2) ? "male" : "female");
  SetLong("This citizen of Keryth strolls casually through town, as if " +
          nominative(this_object()) + " has nothing better to do.");
  SetWander(5);
  SetInventory( ([
    K_OBJ + "/common_pants" : "wear pants"
  ]) );
  SetMorality(-200 + random(150));
  SetLimit(2);
}
