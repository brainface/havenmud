 /* 
  * food
  * balishae 1997
  */
#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("beef ribs");
    SetId( ({ "ribs" }) );
    SetAdjectives( ({ "beef", "meaty" }) );
    SetShort("meaty beef ribs");
    SetLong("Juicy chunks of meat hang off these large beef ribs");
    SetMass(10);
    SetValue(10);
    SetMealType(MEAL_FOOD);
    SetStrength(30);
    SetMealMessages("A napkin would be nice now.",
		    "$N gets grease and juices all over while eating some ribs");
}
