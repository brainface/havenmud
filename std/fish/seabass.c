#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("seabass");
  SetShort("a black seabass");
  SetFight(10);
  SetFood(STD_FISH "seabass_food");
  SetMass(30);
}