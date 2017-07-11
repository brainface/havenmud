// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_FISH;

static void create() {
   ::create();
   SetKeyName("shark");
   SetShort("a dog shark");
   SetId( ({ "shark","dog" }) ); 
   SetAdjectives( ({ "dog" }) );
   SetLong("The dog shark is long and thin, stretching almost "
           "2 meters in length with a circumfrence of only "
           "1/10th a meter.");
   SetFood(FOREST_OBJ + "dogsharkmm");
   SetMass(10);
}
