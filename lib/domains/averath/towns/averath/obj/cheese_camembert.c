/* frenchie cheese for averath
 * mahkefel 2018
 */
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("camembert");
   SetShort("a wheel of camembert cheese");
   SetId( ({ "wheel", "cheese", "camembert" }) );
   SetAdjectives( ({ "wheel", "of", "camembert", "cheese" }) );
   SetLong("A large wheel of creamy cheese with a blue-grey rind.");
   SetAdjectives( ({ "wheel", "of", "camembert" }) );
   SetMass(30);
   SetMealType(MEAL_FOOD);
   SetStrength(50);
   SetPortions(6);
   SetMealMessages("You break off a chunk of camembert and nibble it down.",
                   "$N breaks off a chunk of camembert and nibbles it down.");
}

