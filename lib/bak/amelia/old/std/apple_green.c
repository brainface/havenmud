// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("apple");
   SetShort("a green apple");
   SetId( ({ "apple" }) );
   SetAdjectives( ({ "green","healthy","bright" }) );
   SetLong("The green apple is healthy and bright.");
   SetMass(3);
   SetMealType(MEAL_FOOD);
   SetStrength(15);
   SetMealMessages("As you munch on the apple, a worm comes out "
                     "and slithers away mysteriously.  It is, however, "
                     "an extremely delicious apple.",
                   "$N eats a green apple.");
}
