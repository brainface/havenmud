#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("guppy");
  SetShort("a guppy");
  SetFight(0);
  SetFood(STD_FISH "guppy_food");
  SetMass(5);
}
