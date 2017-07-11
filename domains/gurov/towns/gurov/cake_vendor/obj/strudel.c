//Illura@Haven
//June 2009
#include <lib.h>
#include <meal_types.h>
#include "../cake.h"
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("apple strudel");
   SetShort("an overflowing apple strudel");
   SetId( ({ "strudel", }) );
   SetAdjectives( ({ "overflowing", "apple" }) );
   SetLong("The long cylinder of apple strudel is bursting "
           "with cinnamon coated apple slices. The dough "
           "is flaky and tempting.");
   SetMass(1);
   SetMaterial("natural");
   SetMealType(MEAL_FOOD);
   SetStrength(10);
   SetMealMessages("The apples are firm and sweet.",
                   "$N finishes off a piece of strudel.");
   SetSmell("The strudel smells spicy and delicious.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
