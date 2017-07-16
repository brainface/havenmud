#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("cinnamon roll");
   SetShort("a large cinnamon roll");
   SetId( ({ "roll" }) );
   SetAdjectives( ({ "large","cinnamon" }) );
   SetLong("Sweet bread dough was rolled up, with cinnamon and sugar "
           "and butter in between, to make this cinnamon roll.  It "
           "is very large, gigantic in fact, and it looks very "
           "scrumptious.");
   SetMass(3);
   SetStrength(4);
   SetMealType(MEAL_FOOD);
   SetMealMessages("The cinnamon roll almost seems to dissolve in "
                   "your mouth.","$N savors a delicious cinnamon "
                   "roll.");
}
