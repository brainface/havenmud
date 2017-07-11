/*  A vague foodlike something.
 * For /spells/ranger_food.c
 * Duuk
 */
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("foodlike substance");
  SetShort("a foodlike thing");
  SetLong("This is a foodlike thing.");
  SetId( ({ "thing", "substance", "meal" }) );
  SetAdjectives( ({ "foodlike", "vague" }) );
  SetMealType(MEAL_FOOD);
  SetPortions(5);
  SetMealMessages(
     "You eat " + GetShort() + ".",
      "$N eats " + GetShort() + "." );
 }
