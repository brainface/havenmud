#include <lib.h>
#include "../defs.h"

inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetShort("a torch with black flame");
   SetLong("The torch appears to be ordinary, except for "
           "the black flame which radiates light into "
		   "the surroundings. It reels in dark magic.");
   SetId( ({"torch"}) );
   SetMaterials( ({"wood"}) );
   SetRadiantLight(10);
   SetAdjectives( ({ "black","flame" }) );
   SetKeyName("torch");
   SetPreventGet("The torch is attached to the wall.");
}