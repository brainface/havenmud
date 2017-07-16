#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("red lichen");
   SetShort("a piece of red lichen");
   SetId( ({"lichen","red lichen","piece of lichen","piece of red lichen"}) );
   SetAdjectives( ({ "red" }) );
   SetLong("This is a small piece of yummy red lichen from the north "
     "side of the fenfir trees in the heart of the mountains.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(25);
   SetMealMessages("You munch on some red lichen.",
                   "$N munches on some red lichen.");
   SetTouch("The lichen is slightly moist and smooth.");
   SetSmell("The lichen smells fresh and moist.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
