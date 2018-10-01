//  Portia 12-15-98
//  The armoury version 2.0.4
//  Updated briefly by Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 
  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("the Armoury of Malveillant");
  SetLong(
    "This is the armoury of Malveillant. It and the town smithy are owned "
    "by Lian and his twin brother Fian. A large counter sits at the front "
    "of the store and several shelves line the walls, displaying the armours "
    "for sale. The store is always immaculate and the brothers seem to be "
    "making quite a bit of money."
    );
  SetListen( ([
    "default" : "The sounds of people can be heard.",
    ]) );
  SetSmell( ([
    "default" : "The air smells of leather.",
    ]) );
  SetItems( ([
    ({"armoury", "store", "shop"}) : (:GetLong:),
    ({"counter"}) : 
     "The large counter is made of a highly-polished obsidian. Always tidy "
     "this is where purchases can be made.",
    ({"shelf", "shelves"}) : 
     "Hardwood shelves line the walls of the smithy, displaying wares that "
     "can be purchased.",
    ({"items", "item", "ware", "wares", "armours"}) : 
     "The brothers deal in high-quality wares, various leather, cloth and "
     "metal armours line shelves on the walls.",
    ({"walls", "wall"}) : 
     "The walls hold shelves filled with items for sale.",
    ({"floor", "ground"}) :
      "The floor is kept very tidy.",
    ]) );
  SetItemAdjectives( ([
    "counter" : ({"large", "highly", "polished", "obsidian", "tidy"}),
    "shelf" : ({"hardwood", "wood", "filled", "several", "display"}),
    "items" : ({"high", "quality", "leather", "cloth", "metal"}),
    ]) );
  SetInventory( ([
    MAL_NPC3 + "lian" : 1,
    ]) );
  SetExits( ([
    "out" : MAL_ROOMS3 + "market6",
    ]) );

}
