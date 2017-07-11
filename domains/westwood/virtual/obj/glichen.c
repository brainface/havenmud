#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("green lichen");
   SetShort("a piece of green lichen");
   SetId( ({"lichen","green lichen","piece of lichen","piece of green lichen"}) );
   SetAdjectives( ({ "green" }) );
   SetLong("This is a small piece of delicious green lichen from "
     "the south side of the fenfir trees in the heart of the mountains.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(10);
   SetMealMessages("You munch on some green lichen.",
                   "$N munches on some green lichen.");
   SetTouch("The lichen is slightly moist and slimy.");
   SetSmell("The lichen smells fresh and moist.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
