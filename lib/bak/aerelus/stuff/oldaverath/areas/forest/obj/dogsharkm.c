// Amelia
#include <lib.h>
#include <meal_types.h>
#include <domains.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("shark");
   SetShort("a dog shark");
   SetId( ({ "shark","dog" }) ); 
   SetAdjectives( ({ "dog" }) );
   SetLong("The dog shark is long and thin, stretching almost "
           "2 meters in length with a circumfrence of only "
           "1/10th a meter.");
   SetMealType(MEAL_FOOD);
   SetStrength(40);
   SetMealMessages("The dog shark has a shark, spicey taste.",
                   "$N eats a dog shark.");
   SetMass(10);
}
