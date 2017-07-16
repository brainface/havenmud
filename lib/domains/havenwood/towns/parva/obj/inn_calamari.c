#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("calamari");
   SetShort("a meal of calamari");
   SetId( ({ "meal","calamari" }) );
   SetAdjectives( ({ }) );
   SetLong("The calamari is squid rings with a spicey seafood "
           "tomato sauce. There are several rings on the plate.");
   SetMass(25);
   SetStrength(30);
   SetPortions(5);
   SetMealType(MEAL_FOOD);
   SetMealMessages(
     "$N eat a portion of calamari.  The squid is a little rubbery, but good.",
     "$N eats a portion of calamari."
     );
}
