#include <lib.h>
#include "../lisht.h"
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("itro perch");
  SetShort("an itro perch");
  SetFight(15);
  SetFood(LISHT_OBJ "perch_food");
  SetMass(20);
}
