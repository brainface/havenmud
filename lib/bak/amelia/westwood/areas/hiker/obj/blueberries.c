#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("blueberries");
   SetShort("a handful of blueberries");
   SetId( ({ "handful","blueberry","blueberries","berry","berries" }) );
   SetAdjectives( ({ "handful of","blue","delicious" }) );
   SetLong("The blueberries are large, blue, and ripe.  Not a single "
           "one has any sign of having been infected by a bug, either.");
   SetMass(5);
   SetStrength(15);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N eat up the delicious blueberries, staining your "
                   "mouth and teeth slightly blue.","$N eats some "
                   "blueberries.");
}
