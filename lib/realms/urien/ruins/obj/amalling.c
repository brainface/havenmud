#include <lib.h>
#include "../castle.h"
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("malling");
  SetShort("an albino malling");
  SetFight(80);
  SetFood(RUINS_OBJ "amalling_food");
  SetMass(45);
}
