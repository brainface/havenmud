// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("banana bread");
   SetShort("a loaf of banana bread");
   SetId( ({ "loaf","bread" }) );
   SetAdjectives( ({ "banana","loaf of","golden","brown" }) );
   SetLong("The crust of the banana bread is golden brown.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(40);
   SetMealMessages("That is an awful lot of bread.",
                   "$N finishes off a loaf of banana bread.");
}
