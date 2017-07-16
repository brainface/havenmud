// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_TOUCH;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("cinnamon bread");
   SetShort("a cinnamon bread slice");
   SetId( ({ "slice","bread","bread slice" }) );
   SetAdjectives( ({ "cinnamon","golden","brown" }) );
   SetLong("The crust of the cinnamon bread is golden brown, and the "
           "insides look fully cooked, with a touch of butter on it, "
           "melted into the bread.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(6);
   SetMealMessages("The bread tastes rich and good.",
                   "$N eats a slice of cinnamon bread.");
   SetTouch("The inside of the bread is soft and luxeriously "
            "warm and buttery, but the crust is crispy.");
   SetSmell("The smells of cinnamon spice and warm bread waft off "
            "the cinnamon bread.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}