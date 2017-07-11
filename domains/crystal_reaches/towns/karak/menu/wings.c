// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("sprite wings");
  SetId( ({ "wings" }) );
  SetAdjectives( ({ "sprite" }) );
  SetShort("sprite wings");
  SetLong(
    "These are a pair of wings which were enthusiastically removed from a "
    "sprite, stuck on a thin stick and roasted over a fire. Once lightly "
    "cooked they are served in a thick sauce, often as an accompaniment to "
    "dwarf's head stew."
  );
  SetMealType(MEAL_FOOD);
  SetMass(20);
  SetStrength(10);
  SetMealMessages(
    "You chomp down on the sprite wings.", 
    "$N rips the meat off of $P pair of sprite wings."
  );
}
