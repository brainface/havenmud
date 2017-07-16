// Amelia
#include <lib.h>
#include <domains.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("salmon");
   SetShort("a chum salmon");
   SetId( ({ "salmon","chum" }) ); 
   SetAdjectives( ({ "chum","dog" }) );
   SetLong("Light purple stripes marr the side of this fish.");

   SetMealType(MEAL_FOOD);
   SetStrength(30);
   SetMealMessages("The fish has a light salmon taste, but "
                   "is reminescent of tuna.",
                   "$N eats a chum salmon.");
   SetMass(5);
}
