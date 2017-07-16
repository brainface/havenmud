#include <lib.h>
#include "store.h"

inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("inside the Tannery in the Trunk");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetExits( ([
      "out" : OUT_DIR,
   ]) );
   SetLong(
     "This shop is the center of hide and leather processing for the Havenwood. "
     "Hanging on the walls are hides in various states of curing, and several "
     "completed sets of leather armour hang on display. A long wooden counter "
     "seperates the casual customer from the nastier parts of the tanner's work."
   );   
   SetItems( ([
     ({ "tannery" }) : (: GetLong :),
     ({ "counter" }) : "This wooden counter is bare, and acts as point of sale for the store.",
     ({ "hide", "hides" }) : "The hides are from various small fluffy woodland creatures.",
     ({ "armour", "set", "sets" }) : "The armour appears to be of a very high quality.",
   ]) );
   SetItemAdjectives( ([
     "armour"  : ({ "various", "sets", "of", "completed" }),
     "counter" : ({ "wooden" }),      
   ]) );   
   SetInventory( ([ 
      STORE_DIR + "tornys" : 1,
      STORE_DIR + "odele" : 1,
   ]) );
   SetProperties( ([
      "natural working" : 1,
      "wood working" : 1,
      "leather working" : 1,
      "textile working" : 1,
   ]) );
   SetSmell( ([
     "default" : "The smell of freshly cured leather hangs in the air.",
  ]) );
}
