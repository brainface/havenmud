#include <lib.h>
#include "store.h"

inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("the Leather Boyz Place");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetExits( ([
      "out" : OUT_DIR,
   ]) );
   SetLong(
     "This strange place belongs to Gurk, a Leather Boyz Nob. His "
     "products are generally well known for being of decent quality, and "
     "this store is popular especially among the inhabitants of Karak Varn "
     "and the surrounding area. There is a wooden counter near the door, "
     "where customers may enquire about making a purchase."     
   );   
   SetItems( ([
     ({ "building", "store" }) : (: GetLong :),
     ({ "counter" }) : "This wooden counter is bare, and acts as point of "
     	"sale for the store.",     
   ]) );
   SetItemAdjectives( ([
     "store" : ({ "little" }),
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
