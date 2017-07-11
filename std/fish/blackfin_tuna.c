#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("tuna");
  SetShort("a blackfin tuna");
  SetFight(50);
  SetFood(STD_FISH "blackfin_food");
  SetMass(250);
}