#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("blueberry leaf");
   SetShort("a blueberry leaf");
   SetId( ({ "leaf" }) );
   SetAdjectives( ({ "blue","berry","blueberry" }) );
   SetLong("The leaf has a blue-ish tinge to it, but it is mostly "
           "green.  It is small but also thick.");
   SetMass(1);
   SetStrength(2);
   SetMealType(MEAL_FOOD);
   SetMealMessages("The leaf has a slightly sour taste to it.", 
                   "$N eats a leaf.");
}
