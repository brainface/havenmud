#include <lib.h>
#include "store.h"

inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("Temu's Rag's");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetExits( ([
      "out" : OUT_DIR,
   ]) );
   SetLong(
     "This is a small hut that is owned by Temu. Temu is the local leather"
     " crafter in Kresh. His hut has a small counter in the middle seperating"
     " customers from the inventory and providing Temu a little protection"
     " should anyone violently disagree with his prices. The rest of the"
     " hut is bare and crude in craftsmanship."     
   );   
   SetItems( ([
     ({ "building", "store", "hut" }) : (: GetLong :),
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
