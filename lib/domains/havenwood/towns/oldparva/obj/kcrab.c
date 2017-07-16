#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("crab");
   SetShort("a king crab");
   SetId( ({ "crab" }) );
   SetAdjectives( ({ "king" }) );
   SetLong("Eight tough prickly shell-covered legs poke out of "
           "relatively weak shell of the body of the king "
           "crab.  It is red on top and in the center, fading "
           "through orange-red and a slightly pink color as "
           "it turns towards the white of the bottum.");
   SetMass(60);
   SetStrength(80);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N chew up a raw king crab!",
                   "$N chews up a raw crab.");
   if(!random(50)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(20);
      SetMealMessages("$N chew up a raw crab, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw crab.");
   }
}
