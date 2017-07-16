#include <lib.h>
#include "../rook.h"
inherit LIB_FISH;

static void create() {
  fish::create();
  SetKeyName("fish");
  SetFood(R_OBJ + "d_fish");
  SetShort("a little dragon fish");
  SetLong("This is a tniy dragon fish, names for its ferocious "
    "looking jawline and teeth.");
  SetMass(30);
  SetId( ({ "fish", "dragon fish" }) );
  }
