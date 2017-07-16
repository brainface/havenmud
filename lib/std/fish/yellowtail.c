#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("snapper");
  SetShort("a yellowtail snapper");
  SetFight(20);
  SetFood(STD_FISH "snapper_food");
  SetMass(50);
}