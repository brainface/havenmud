#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("lunchbox sandwich");
   SetShort("a lunchbox sandwich");
   SetId( ({ "sandwich" }) );
   SetAdjectives( ({ "lunchbox","lunch","box" }) );
   SetLong("The sandwich is made from two slices of fresh wheat bread "
           "with lettuce, tomatoes, and some sort of meat; it looks "
           "like it might be chicken.");
   SetMass(10);
   SetStrength(30);
   SetMealType(MEAL_FOOD);
   SetMealMessages("A little of the meat falls out as $N eat it.",
                   "$N eats a sandwich.");
}
