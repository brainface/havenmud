// Proximo@Pax Imperialis
// 06/19/2003

#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("red apple");
  SetId( ({ "apple" }) );
  SetAdjectives( ({ "red" }) );
  SetShort("a red apple");
  SetLong(
     "This piece of fruit is that from a red apple tree. This apple is a "
     "sweet fruit which is very popular amongst a variety of people. "
     );
  SetStrength(20);
  SetValue(15);
  SetMealType(MEAL_FOOD);
  SetMealMessages( ({
     "$N eat a delicious red apple. ",
     "$N eats a red apple. ",
  }) );
}
