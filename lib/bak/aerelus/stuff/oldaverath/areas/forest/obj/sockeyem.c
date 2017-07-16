// Amelia
#include <lib.h>
#include <domains.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("salmon");
   SetShort("a sockeye salmon");
   SetId( ({ "salmon","sockeye" }) ); 
   SetAdjectives( ({ "red","sockeye" }) );
   SetLong("Bright red near the head, the remainder of the salmon "
           "is predominantly green.");
   SetMealType(MEAL_FOOD);
   SetStrength(35);
   SetMealMessages("The fish has a strong, flavorful salmon "
                   "taste.","$N eats a sockeye salmon.");
   SetMass(15);
}
