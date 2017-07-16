#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("grapes");
  SetId( ({ "grapes", "fruit"}) );
  SetAdjectives( ({ "bunch", "of" }) );
  SetShort("a bunch of grapes");
  SetMass(1);
  SetLong("This is a bunch of dark blue grapes. These grapes "
          "look plump and juicy.");
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetPortions(5);
  SetMealMessages(
    "You eat a few grapes.  They taste sweet.",
    "$N eats a few grapes.");
}
