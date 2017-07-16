//  Empty Shop for Later Player Owned
//  Updated by Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 
  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("an empty shop");
  SetLong(
     "A spotless counter sits against the far wall, and empty shelves line "
     "the walls. Not a speck of dust can be found anywhere in this unoccupied "
     "space, and it seems ready for a new tenant to move in."
     );
  SetListen( ([
     "default" : "The only noise is from the voices in the marketplace outside.",
     ]) );
  SetSmell( ([
     "default" : "The room smells strongly of fresh wood.",
     ]) );
  SetItems( ([
     ({"room", "shop", "store", "space"}) : (:GetLong:),
     ({"counter"}) :
     	 "The wooden counter rests against a back wall, ready to be covered in "
     	 "wares.",
     ({"wall","walls"}) :
     	 "The walls are bare save some empty shelves.",
     ({"shelf", "shelves"}) :
     	 "These carved wooden shelves are completely empty.",
     ({"floor", "ground"}) :
     	 "The floor is spotless.",
     ]) );
  SetItemAdjectives( ([
     "counter" : ({"spotless", "wooden", "wood"}),
     "wall" : ({"bare"}),
     "shelf" : ({"empty", "carved", "wooden", "wood"}),
     "floor" : ({"spotless"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "out" : MAL_ROOMS3 + "market2",
     ]) );

}
