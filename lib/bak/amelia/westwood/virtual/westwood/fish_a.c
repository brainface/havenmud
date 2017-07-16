// Amelia@Haven

#include <lib.h>
inherit LIB_FISH;
#include "../westwood.h"

static void create() {
   fish::create();
   SetKeyName("rainbow fish");
   SetShort("a rainbow fish");
   SetId( ({ "rainbow fish","fish" }) );
   SetAdjectives( ({ "rainbow" }) );
   SetLong("The scales of this fish are of a myriad of colors.");
   SetMass(15);
   SetFood("fish_a_meal");
}
