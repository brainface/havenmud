// Proximo@Pax Imperialis
// 06/19/2003

#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("carrot");
  SetId( ({ "carrot" }) );
  SetAdjectives( ({ "orange" }) );
  SetShort("an orange carrot");
  SetLong(
      "This vegetable is an orange carrot that looks to have been freshly "
      "picked from the ground. "
  		);
  SetStrength(10);
  SetValue(9);
  SetMealType(MEAL_FOOD);
  SetMealMessages( ({
     "$N eat a tasty orange carrot. ",
     "$N eats an orange carrot. ",
  }) );
}
