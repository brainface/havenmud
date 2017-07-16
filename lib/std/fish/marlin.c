#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("marlin");
  SetShort("a blue marlin");
  SetFight(80);
  SetFood(STD_FISH "marlin_food");
  SetMass(350);
}