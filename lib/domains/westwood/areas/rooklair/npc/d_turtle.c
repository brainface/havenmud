#include <lib.h>
#include "../rook.h"
inherit LIB_FISH;

static void create() {
  fish::create();
  SetKeyName("turtle");
  SetFood(R_OBJ + "d_turtle");
  SetShort("a little dragon turtle");
  SetLong("This is a tniy dragon turtle, names for its ferocious "
    "looking shell that seems as hard as a dragons scales.");
  SetMass(30);
  SetId( ({ "turtle", "dragon turtle" }) );
  }
