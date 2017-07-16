// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_FISH;

static void create() {
   ::create();
   SetKeyName("salmon");
   SetShort("a sockeye salmon");
   SetId( ({ "salmon","sockeye" }) ); 
   SetAdjectives( ({ "red","sockeye" }) );
   SetLong("Bright red near the head, the remainder of the salmon "
           "is predominantly green.");
   SetFood(FOREST_OBJ + "sockeyem");
   SetMass(5);
}
