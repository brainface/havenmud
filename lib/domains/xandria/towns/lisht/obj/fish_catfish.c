#include <lib.h>
#include "../lisht.h"
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("catfish");
  SetShort("a catfish");
  SetFight(20);
  SetFood(LISHT_OBJ "catfish_food");
  SetMass(40);
}
