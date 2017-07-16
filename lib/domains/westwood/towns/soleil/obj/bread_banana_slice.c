// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("banana bread");
   SetShort("a banana bread slice");
   SetId( ({ "slice","bread","bread slice" }) );
   SetAdjectives( ({ "banana","golden","brown" }) );
   SetLong("The crust of the banana bread is golden brown, and the "
           "insides look fully cooked, with a touch of butter on it, "
           "melted into the bread.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(7);
   SetMealMessages("The bread tastes rich and good.",
                   "$N eats a slice of banana bread.");
   SetTouch("The crust of the bread is firm to the touch, but it "
            "feels warm and is very soft and buttery on "
            "the inside.");
   SetSmell("A warm, steamy smell of banana floats off the bread.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
