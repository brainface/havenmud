//   Portia 12-11-98
//     The path to the general store.
//     version 2.0
// Quick Patch - This room will be completely redone with the addition of 
//   a Malv Academy in the future.
// UPDATED 1/13/13 BY OHTAR (adding a player in per Duuk as well as updating
// room to work correctly for estates.)
//   Aless 3/06

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
  
  SetShort("a muddy path");
  SetClimate("underground");
  SetExits( ([
     "south" : MAL_ROOMS + "center2",
     "east" : MAL_ROOMS + "path10",
     "west" : MAL_ROOMS + "path16",
     ]) );
  SetListen( ([
     "default" : "The area is quite loud.",
     ]) );
  SetSmell( ([
     "default" : "The area smells of leather and metal.",
     ]) );
  SetInventory( ([
     ]) );
  SetLong(
     "This path is quiet muddy and looks as though "
     "it is used very much. There are many footprints here "
     "that seem to go in all directions. Most of them however "
     "lead north towards a large building. This building is "
     "made of obsidian. This building appears to be shop "
     "of some sort. It is made of obsidian like all of the "
     "other buildings in Malveillant. The building here "
     "has many lights as well as a sign on the front of it."
     );
  SetItems( ([
     ({"path"}) : (:GetLong:),
     ({"footprints", "footprint"}) : 
         "The footprints lead in all directions.",
     ({"building", "shop"}) : 
           "The building is made up of obsidian bricks. They are "
           "put together in an extraordinary design. There are four "
           "windows on the building, two on each side. One on each "
           "side of the door but elevated about 5 feet from the door "
           "height as well as one above each of them on the second "
           "story of the building. These windows are made up of "
           "stained glass which causes them to have a very beautiful "
           "design in them. Each window has a light on the top "
           "outside corner and the lower inside corner. This is "
           "intentional to cause an arrow looking effect pointing "
           "at the door. The door on the building is made of mithril. "
           "It has a rather large window in it which is also made up "
           "of stained glass. This window has letters on it which read: "
           "JynXx's no so Junk!",
     ({"sign"}) :
           "The large sign that reads: JynXx's not so Junk!"
     ]) );
  SetItemAdjectives( ([
     "path" : ({"muddy", "used"}),
     "footprints" : ({"many"}),
     "building" : ({"large", "busy", "obsidian"}),
     "sign" : ({"large"}),
     ]) );
  SetEnters( ([
   ({"building", "shop"}) : MAL_ROOMS + "p_inn",
   ]) );
 }
