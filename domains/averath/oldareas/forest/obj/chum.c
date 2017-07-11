// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_FISH;

static void create() {
   ::create();
   SetKeyName("salmon");
   SetShort("a chum salmon");
   SetId( ({ "salmon","chum" }) ); 
   SetAdjectives( ({ "chum","dog" }) );
   SetLong("Light purple stripes marr the side of this fish.");
   SetFood(FOREST_OBJ + "chumm");
   SetMass(5);
}
