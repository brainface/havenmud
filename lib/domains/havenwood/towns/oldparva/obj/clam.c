#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("clam");
   SetShort("a raw clam");
   SetId( ({ "clam" }) );
   SetAdjectives( ({ "raw" }) );
   SetLong("The raw clan quivers in its shell, mooshing around "
           "patiently, dumb and brainless.");
   SetMass(2);
   SetStrength(5);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N eat a raw clam.",
                   "$N eats a raw clam.");
   if(!random(30)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(2);
      SetMealMessages("$N chew up a raw clam, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw clam.");
   }
}
