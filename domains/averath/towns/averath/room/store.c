// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("in a small store");
  SetLong(
    "This store, while rather small, is home to shelves full of items for "
    "sale. A wooden counter serves as a point of sale where the owner usually "
    "stands, awaiting customers. The building is fairly run down, showing "
    "how difficult it must be for the owner to make a profit while competing "
    "with dealers in the Averath market."
  );
  SetItems( ([
    ({ "building", "store" }) : (: GetLong :),
    ({ "shelves", "items" }) : "Various items are on display on these "
      "shelves. The owner of the store could probably help anyone who was "
      "interested in buying any of them.",
    ({ "counter", "point", "sale" }) : "The owner of the store usually "
      "stands behind this counter, ready to help customers.",        
  ]) );
  SetItemAdjectives( ([
    "store" : ({ "small", }),
    "counter" : ({ "wooden" }),
  ]) );
  SetInventory( ([
    AVERATH_NPC "shopkeep" : 1,
    AVERATH_NPC "citizen" : 1,
    AVERATH_NPC "guard" : 1,
  ]) );
  SetListen( ([
     "default" : "Sounds of city life drift in to the store from outside.",
  ]) );
  SetSmell( ([
     "default" : "The store strongly smells of the oil used in the torches "
       "which the owner usually has in stock.",
  ]) );  
  SetExits( ([    
    "out" : AVERATH_ROOM "road3",    
  ]) );    
}