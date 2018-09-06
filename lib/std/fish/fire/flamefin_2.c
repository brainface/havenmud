#include <lib.h>
#include <std.h>
#include <meal_types.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("greater flamefin");
  SetShort("a greater flamefin");
  SetLevel(50);
  SetFood(STD_FISH "fire/flamefin_food_2");
  SetMass(FISH_SIZE_MEDIUM);
}

