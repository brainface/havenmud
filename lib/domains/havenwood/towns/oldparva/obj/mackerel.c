#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("mackarel");
   SetShort("a raw mackarel");
   SetId( ({ "mackarel" }) );
   SetAdjectives( ({ "raw" }) );
   SetLong("The mackarel is a blueish color with a few tinges of "
           "orange on the head.  Its eyes roll around in their "
           "sockets.  The bottom on the fish is fish-belly "
           "white.");
   SetMass(35);
   SetStrength(35);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N chew up a raw mackarel.","$N chews up a "
                   "raw mackarel.");
   if(!random(40)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(10);
      SetMealMessages("$N chew up a raw mackarel, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw mackarel.");
   }
}
