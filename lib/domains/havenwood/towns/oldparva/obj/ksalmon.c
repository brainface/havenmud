#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("salmon");
   SetShort("a raw salmon");
   SetId( ({ "salmon" }) );
   SetAdjectives( ({ "raw","king" }) );
   SetLong("The salmon is a nice pink color on the inside, and the "
           "outside is a slimy green-pink color.  It is quite "
           "large and looks almost tasty.");
   SetMass(55);
   SetStrength(75);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N chew up a raw salmon.","$N chews up a "
                   "raw salmon.");
   if(!random(45)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(15);
      SetMealMessages("$N chew up a raw salmon, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw salmon.");
   }
}
