#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("croissant");
   SetShort("a buttery croissant");
   SetId( ({ "croissant","butter","flake","flakes" }) );
   SetAdjectives( ({ "buttery" }) );
   SetLong("Flakey bits of crust peel off the croissant in little "
           "leafs of buttery pastry.");
   SetMass(3);
   SetMealType(MEAL_FOOD);
   SetStrength(9+random(3));
   SetMealMessages("The buttery flakes melt scrumptiously in your mouth.",
                   "$N savours a buttery croissant.");
}
