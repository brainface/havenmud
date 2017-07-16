// amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("gray fish");
   SetShort("a gray fish");
   SetId( ({ "fish" }) );
   SetAdjectives( ({ "gray" }) );
   SetLong("The scales of this fish are all varying shades of gray.");
   SetMass(10);
   SetMealType(MEAL_FOOD);
   SetStrength(25);
   SetMealMessages("You eat a gray fish.",
                   "$N eats a gray fish.");
}