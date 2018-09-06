#include <lib.h>
#include <std.h>
#include <meal_types.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("wooly whiting");
  SetShort("a wooly whiting");
  SetLevel(10);
  SetFood(STD_FISH "wooly_whiting_food");
  SetMass(FISH_SIZE_SMALL);
}
