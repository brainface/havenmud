#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("mackerel");
  SetShort("a cero mackerel");
  SetFight(40);
  SetFood(STD_FISH "mackerel_food");
  SetMass(36);
}
