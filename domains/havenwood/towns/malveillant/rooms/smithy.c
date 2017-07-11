/*    Portia 12-15-98
      The smithy
      version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("The Smithy of Malveillant");
 SetClimate("indoors");
 SetExits( ([
   "out" : MAL_ROOMS + "path16",
   ]) );
 SetInventory( ([
   MAL_NPC + "fian" : 1,
   ]) );
 SetSmell( ([
   "default" : "The air smells of metal and wood.",
   ]) );
 SetListen( ([
   "default" : "The sounds of people can be heard.",
   ]) );
 SetLong("This is the smithy of Malveillant. It is "
   "owned by Lian and his twin brother Fian. The pair "
   "also own the armoury across town. A large counter sits "
   "at the front of the store and several shelves adorn the "
   "walls. The shop seems to be doing quite well and making "
   "lots of money.");
 SetItems( ([
   ({"smithy", "shop"}) : (:GetLong:),
   "counter" : "The large counter is where purchases are made.",
   ({"shelf", "shelves"}) : "The shelves are full of items "
       "to purchase.",
   ({"items", "item"}) : "These items are for sale.",
   ({"walls", "wall"}) : "The walls are full of goods.",
   ]) );
 SetItemAdjectives( ([
   "counter" : "large",
   "shelf" : "several",
   ]) );
 }
