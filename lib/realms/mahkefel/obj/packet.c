#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("mayonnaise");
   SetShort("a packet of mayonnaise");
   SetId( ({ "packet","mayonnaise" }) );
   SetAdjectives( ({ "packet", "of" }) );
   SetLong("How thoughtful!");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(5);
   SetPortions(1);
   SetMealMessages("SLLUUURRRRRPPP.",
                   "$N SLLUUURRRRRPPPS.");
}

