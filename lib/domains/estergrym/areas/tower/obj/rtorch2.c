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
   SetRadiantLight(15);
   SetAdjectives( ({ "black","flame" }) );
   SetKeyName("torch");
   SetProperty("history",
    "This torch was conjured from an evil mage with immense "
	"powers and tossed aside for more sinister acts."
   );
   SetProperty("magic",                                             
    "This torch burns in magical darkness. It has an everlasting "
	"flame which never burns out. "
   ); 
}