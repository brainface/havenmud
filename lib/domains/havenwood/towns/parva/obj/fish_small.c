#include <lib.h>
#include "../parva.h"
inherit LIB_FISH;

static void create() {
   fish::create();
   SetKeyName("small fish");
   SetShort("a small fish");
   SetId( ({ "fish" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("The small fish is brown and green.");
   SetMass(5);
   SetFood(PARVA_OBJ + "fish_food");
}
