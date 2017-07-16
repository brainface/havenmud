#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
 
static void create() {
   meal::create();
   SetKeyName("Eclatish beer");
   SetShort("a mug of Eclatish beer");
   SetId( ({ "mug","beer","mug of beer","mug of eclatish beer" }) );
   SetAdjectives( ({ "eclatish" }) );
   SetLong("The Eclatish beer is strong and well flavored.");
   SetMealType(MEAL_ALCOHOL|MEAL_DRINK);
   SetStrength(45);
   SetMealMessages("The Eclatish beer feels good going down, and all "
                   "your muscles start to relax.","$N relaxes with "
                   "some Eclatish beer.");
   SetEmptyName("beer mug");
   SetEmptyShort("a beer mug");
   SetEmptyLong("The beer mug has some residue left in it.");
   SetMass(10);
}