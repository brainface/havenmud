// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("cinnamon bread");
   SetShort("a loaf of cinnamon bread");
   SetId( ({ "loaf","bread" }) );
   SetAdjectives( ({ "cinnamon","loaf of","golden","brown" }) );
   SetLong("The crust of the cinnamon bread is golden brown.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(40);
   SetMealMessages("That is an awful lot of bread.",
                   "$N finishes off a loaf of cinnamon bread.");
}
