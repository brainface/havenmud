#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("warm yam");
   SetShort("a warm yam");
   SetId( ({ "yam","potato" }) );
   SetAdjectives( ({ "warm","sweet","moist","scrumptious" }) );
   SetLong("The sweet potato has small slits in its outer skin to "
           "prevent it from exploding while being cooked.  The inside "
           "of the yam, beneath the rough skin, is moist and orange.");
   SetMass(13);
   SetMealType(MEAL_FOOD);
   SetStrength(16);
   SetMealMessages("The moist potato goes down easily.",
                   "$N eats a scrumptious yam.");
}