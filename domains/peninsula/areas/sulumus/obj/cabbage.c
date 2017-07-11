// Proximo@Pax Imperialis
// 06/25/2003

#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("cabbage");
  SetId( ({ "cabbage" }) );
  SetAdjectives( ({ "green" }) );
  SetShort("a green cabbage");
  SetLong(
     "This vegetable is a green cabbage. It looks fresh and ripe, perfect "
     "for those whom are hungry. "
  );
  SetStrength(30);
  SetValue(16);
  SetMealType(MEAL_FOOD);
  SetMealMessages( ({
     "$N eat a wholesome green cabbage. ",
     "$N eats a green cabbage. ",
  	 }) );
}
