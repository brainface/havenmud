#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("trout");
  SetShort("a heavy trout");
  SetFight(5);
  SetFood(STD_FISH "trout_food");
  SetMass(10);
}
