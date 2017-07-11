// Amelia@Haven

#include <lib.h>
inherit LIB_FISH;
#include "../goblin.h"

static void create() {
   fish::create();
   SetKeyName("gray fish");
   SetShort("a gray fish");
   SetId( ({ "gray fish","fish" }) );
   SetAdjectives( ({ "gray" }) );
   SetLong("The scales of this fish are all varying shades of gray.");
   SetMass(15);
   SetFood( G_OBJ + "fish_b_meal");
}