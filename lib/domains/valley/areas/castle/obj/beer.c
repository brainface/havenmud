#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("mug of beer");
   SetShort("a tall mug of beer");
   SetId( ({ "mug","beer","mug of beer" }) );
   SetAdjectives( ({ "tall" }) );
   SetLong("There is beer in the tall mug, looking rather good to drink.");
   SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
   SetStrength(25);
   SetMealMessages("The beer feels good going down, and all your muscles "
                   "start to relax.","$N relaxes with a mug of beer.");
   SetEmptyName("beer mug");
   SetEmptyShort("a beer mug");
   SetEmptyLong("The beer mug has some residue left in it.");
   SetMass(8);
}