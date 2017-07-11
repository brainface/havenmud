#include <lib.h>
inherit LIB_FISH;
#include "../underdark.h"

static void create() {
  fish::create();
  SetKeyName("cave fish");
  SetFood( U_OBJ + "fishfood");
  SetShort("a cave fish");
  SetLong("This is a blind little cave fish.");
  SetMass(20);
  SetId( ({ "fish", "cave fish", "blind fish" }) );
  }
