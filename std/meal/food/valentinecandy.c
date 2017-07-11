#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("box of candies");
   SetShort("a heart-shaped box of Valentine's Day candy");
   SetId( ({ "box", "candy", "candies" }) );
   SetAdjectives( ({ "box", "heart", "shaped", "of", "valentine's", "valentine", "day" }) );
   SetLong(
     "This is a large red heart shaped box of Valentine's Day candy. "
     "Enjoy and Happy V-day from Duuk."
     );
   SetMass(2);
   SetMealType(MEAL_FOOD|MEAL_CAFFEINE);
   SetStrength(10);
   SetPortions(6);
   SetMealMessages("You eat some Valentine's candy.",
                   "$N eats some Valentine's candy.");
}
