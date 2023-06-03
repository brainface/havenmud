#include <lib.h>
#include "../castle.h"
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("muddling");
  SetShort("a muddling");
  SetFight(1);
  SetFood(RUINS_OBJ "muddling_food");
  SetMass(4);
}
