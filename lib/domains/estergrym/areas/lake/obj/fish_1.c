// Coded by Zeratul 11-27-99
#include <lib.h>
#include "../lake.h"
inherit LIB_FISH;

static void create() {
  fish::create();
  SetKeyName("small fish");
  SetShort("a small fish");
  SetId( ({ "small fish","fish" }) );
  SetAdjectives( ({ "small" }) );
  SetLong("The small fish is about six inches in size. "
     );
  SetMass(15);
  SetFood( LAKE_OBJ + "/fish_1_meal" );
}
