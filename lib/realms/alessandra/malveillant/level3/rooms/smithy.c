//  Portia 12-15-98
//  The smithy version 2.0
//  Updated briefly by Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("the Smithy of Malveillant");
  SetLong(
     "This is the smithy of Malveillant. It is owned by Lian and "
     "his twin brother Fian. The pair also own the armoury just down "
     "the path from here. A large counter sits at the front of the store "
     "and several shelves adorn the walls. The shop seems to be doing "
     "quite well and making lots of money."
     );
  SetSmell( ([
     "default" : "The air smells of metal and wood.",
     ]) );
  SetListen( ([
     "default" : "The sounds of people can be heard.",
     ]) );
  SetItems( ([
     ({"smithy", "shop"}) : (:GetLong:),
     ({"counter"}) : 
     	 "The large counter is where purchases are made.",
     ({"shelf", "shelves"}) : 
     	 "The simple shelves are full of items to purchase.",
     ({"items", "item"}) : 
     	 "These items are for sale.",
     ({"walls", "wall"}) : 
     	 "The walls are lined with shelves.",
     ]) );
  SetItemAdjectives( ([
     "counter" : "large",
     "shelf" : ({"several", "simple", "full"}),
     ]) );
  SetInventory( ([
     MAL_NPC3 + "fian" : 1,
     ]) );
  SetExits( ([
     "out" : MAL_ROOMS3 + "market7",
     ]) );



}
