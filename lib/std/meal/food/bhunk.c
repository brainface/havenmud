#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("bread hunk");
   SetShort("a hunk of bread");
   SetId( ({ "hunk", "bread" }) );
   SetAdjectives( ({ "hunk", "of" }) );
   SetLong("The bread is grainy and full of whole wheat chunks, but "
           "appears to be tasty.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(15);
   SetMealMessages("The bread tastes heavenly.",
                   "$N looks a bit healthier after eating some bread.");
}
