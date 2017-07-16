// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_TOUCH;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("cinnamon bread");
   SetShort("a cinnamon bread loaf");
   SetId( ({ "loaf","bread","bread loaf" }) );
   SetAdjectives( ({ "cinnamon","golden","brown" }) );
   SetLong("The crust of the cinnamon bread is golden brown.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(40);
   SetMealMessages("That is an awful lot of bread.",
                   "$N finishes off a loaf of cinnamon bread.");
   SetTouch("The inside of the bread is soft and luxeriously "
            "warm and buttery, but the crust is crispy.");
   SetSmell("The smells of cinnamon spice and warm bread waft off "
            "the cinnamon bread.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}