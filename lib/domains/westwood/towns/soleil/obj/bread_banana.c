// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("banana bread");
   SetShort("a banana bread loaf");
   SetId( ({ "loaf","bread","bread loaf" }) );
   SetAdjectives( ({ "banana","golden","brown" }) );
   SetLong("The crust of the banana bread is golden brown.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(40);
   SetMealMessages("That is an awful lot of bread.",
                   "$N finishes off a loaf of banana bread.");
   SetTouch("The crust of the bread is firm to the touch, but it "
            "feels warm and is probably very soft and buttery on "
            "the inside.");
   SetSmell("A warm, steamy smell of banana floats off the bread.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}