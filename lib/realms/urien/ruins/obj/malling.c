#include <lib.h>
#include "../castle.h"
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("malling");
  SetShort("a malling");
  SetFight(10);
  SetFood(RUINS_OBJ "malling_food");
  SetMass(17);
}
