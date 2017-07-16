#include <lib.h>
#include "../rook.h"
inherit LIB_FISH;

static void create() {
  fish::create();
  SetKeyName("snake");
  SetFood(R_OBJ + "d_snake");
  SetShort("a long dragon snake");
  SetLong("This is a long dragon snake. It is appears similiar to "
    "how dragons were once depicted in drawings.");
  SetMass(30);
  SetId( ({ "snake", "dragon snake" }) );
  }
