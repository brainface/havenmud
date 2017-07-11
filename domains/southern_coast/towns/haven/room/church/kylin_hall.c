//
// Filename: kylin_hall.c
// The Kylin Hall
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the Room of the Faithful");
   SetProperty("no conjuring", 1);
   SetProperty("no attack", 1);
   SetProperty("no teleport", 1);
  SetProperty("no magic", 1);
   SetProperty("no steal", 1);
   SetNewsgroups( ({ "religion.kylin" }) );
   SetExits( ([
      "south" : "sanctuary",
   ]) );
   SetLong("This is a quiet room for use by faithful followers of "
           "Duuktsaryth to rest. This place is under his protection. "
           "Scattered about the room are various chairs and upholstered "
           "sofas for rest. A large fireplace lies embedded in the north "
           "wall to give this room a pleasant atmosphere.");
   SetItems( ([
      ({ "sofa", "chair", "sofas", "chairs", "furnishing", "furnishings" }) :
         "The furnishings are basic and functional, yet oddly "
         "comfortable, normal upholstered goods.",
      ({ "fireplace" }) : 
         "The fireplace is idle, yet looks ready at a moments notice "
         "to burst into flames.",
      ({ "wall" }) :
         "The northern wall of this room contains a very large fireplace.",
   ]) );
   SetItemAdjectives( ([
      "furnishing" : ({ "basic", "functional", "comfortable",
                        "upholstered" }),
      "fireplace" : ({ "idle", "large" }),
      "wall" : ({ "north", "northern" }),
   ]) );
   SetInventory( ([
   ]) );
   SetSmell( ([
      "default" : "A peaceful smell of fresh air lists into the room.",
    ]) );
   SetListen( ([
      "default" : "Sound in the room is muffled, seeming to keep the peace.",
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:41:38 1999. */
