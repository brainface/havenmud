#include <lib.h>
inherit LIB_FISH;
#include "../underdark.h"

static void create() {
  fish::create();
  SetKeyName("snail");
  SetFood( U_OBJ + "snailfood");
  SetShort("a snail");
  SetLong("This is a large aquatic snail.");
  SetMass(15);
  SetId( ({ "snail", "large snail", "aquatic snail" }) );
  }
