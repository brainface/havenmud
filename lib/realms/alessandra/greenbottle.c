#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("bottle");
  SetShort("a green glass bottle");
  SetFight(10);
  SetFood(STD_FISH "greenbottle_food");
  SetMass(10);
}


