#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("warm brownie");
   SetShort("a warm brownie");
   SetId( ({ "brownie","square" }) );
   SetAdjectives( ({ "warm","large","brown" }) );
   SetLong("The brownie is warm, soft, and tasty-looking.  It is "
           "a large, brown square.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(5);
   SetMealMessages("The brownie warms your mouth.",
                   "$N eats a brownie.");
   SetSmell("The brownie smells like warm chocolate.");
   SetTouch("The brownie is soft and warm.");
}
mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
