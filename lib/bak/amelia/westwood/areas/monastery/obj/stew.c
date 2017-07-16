#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("rainbow fish stew");
   SetShort("rainbow fish stew");
   SetId( ({ "stew","fish","fish stew" }) );
   SetAdjectives( ({ "rainbow" }) );
   SetLong("Little bits of yummy rainbow fish fill the thick stew.");
   SetMass(8);
   SetStrength(40);
   SetMealType(MEAL_FOOD);
   SetMealMessages("The fish goes down well, delicious and tasty.",
                   "$N smiles contentedly while eating some rainbow "
                      "fish stew.");
}