#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("oyster");
   SetShort("a raw oyster");
   SetId( ({ "oyster" }) );
   SetAdjectives( ({ "raw" }) );
   SetLong("The oyster doesn't have eyes that one could make out "
           "from the white mush in the curvy shell, but "
           "it is easy to imagine two tiny eyes staring "
           "up, worrying about it's imminent death.");
   SetMass(5);
   SetStrength(15);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N tip a raw oyster back and eat it!",
                   "$N tips a raw oyster back and eats it.");
   if(!random(60)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(4);
      SetMealMessages("$N chew up a raw oyster, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw oyster.");
   }
}
