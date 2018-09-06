#include <lib.h>
#include <std.h>
#include <meal_types.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("lesser flamefin");
  SetShort("a lesser flamefin");
  SetLevel(5);
  SetFood(STD_FISH "fire/flamefin_food_1");
  SetMass(FISH_SIZE_SMALL);
}

