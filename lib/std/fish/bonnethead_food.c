#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("bonnethead shark");
    SetId( ({ "shark","fish" }) );
    SetAdjectives( ({ "bonnethead" }) );
    SetShort("a bonnethead shark");
    SetLong("This is a bonnethead shark, a terrifyingly large creature grimly colored "
            "the shade of bleached bone. Its head is flat and wide, like an arrowhead. "
            "It looks like it would make a decent meal.");
    SetMass(150);
    SetMealType(MEAL_FOOD);
    SetStrength(40);
  SetValue(300);
    SetMealMessages("It tastes excellent.", "$N eats a bonnethead shark.");
}
