#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("wine");
   SetShort("a tall glass of wine");
   SetId( ({ "wine", "glass" }) );
   SetAdjectives( ({ "tall", "of", "glass" }) );
   SetLong("There is wine in the tall glass, looking rather good to drink.");
   SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
   SetStrength(25);
   SetMealMessages("The wine feels good going down, and all of your muscles "
                   "start to relax.","$N relaxes with a glass of wine.");
   SetEmptyName("wine glass");
   SetEmptyShort("a wine glass");
   SetEmptyLong("The wine mug has some residue left in it.");
   SetMass(8);
}
