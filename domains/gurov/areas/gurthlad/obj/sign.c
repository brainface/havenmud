#include <lib.h>
inherit LIB_ITEM;
 
 
static void create() {
   item::create();
   SetShort("a large wooden sign");
   SetLong("The large wooden sign has been nailed into the ground.");
   SetRead("default", "The plains of Gurthlad.");
   SetId( ({"sign"}) );
   SetAdjectives( ({ "large","wooden" }) );
   SetKeyName("sign");
   SetPreventGet("The sign post is imbedded to deep in the ground to get "
                 "it out.");
}
