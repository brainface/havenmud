// Amelia@haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("rainbow fish");
   SetShort("a rainbow fish");
   SetId( ({ "fish" }) );
   SetAdjectives( ({ "rainbow" }) );
   SetLong("The scales of this fish are a myriad of colors.");
   SetMass(10);
   SetMealType(MEAL_FOOD);
   SetStrength(25);
   SetMealMessages("You eat a rainbow fish.",
                   "$N eats a rainbow fish.");
}
