#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("squid");
   SetShort("a black squid");
   SetId( ({ "squid" }) );
   SetAdjectives( ({ "black" }) );
   SetLong("Eight loose rubbery tentacles hang down from the "
           "rubbery black body of the squid.  Its eyes look "
           "mournful and angry, peering out on the world from "
           "the dead corpse.");
   SetMass(30);
   SetStrength(40);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N chew up a raw squid!",
                   "$N chews up a raw squid.");
   if(!random(45)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(5);
      SetMealMessages("$N chew up a raw squid, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw squid.");
   }
}
