
//coded by Syra 8/97
#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small pathway");
	SetDomain("Havenwood");
  SetLong("The trees are very dense here, but there seems to "
     "be an opening to the west. The animal trail "
    "continues to find the only clear path. "
    "The large trees provide a great amount of shade here, "
    "nearly preventing all light from entering. "
    "The trail leads to the east and the west from here through the "
     "dense underbrush of the forest.");
  SetItems( ([
             ({"havenwood","wood","woods"}) : (:GetLong:),
             ({"dense trees","trees","wall","tree","dense tree"}): 
               "The trees form a "
               "literal wall in every direction except that dictated "
               "by the animal path. ",
             ({"animal trail","trail","animal path","clear path",
               "path"}) : "The animal trail seems "
               "to be the only path through the thick underbrush. ",
             ({"solid canopy","canopy","opening"}) : "The solid "
               "canopy seems to "
               "open up to the east.",
             ({"thick underbrush","dense underbrush","underbrush"}): 
               "The underbrush is very dense and thick. ",
     ]) );
  SetExits( ([
            "west"   : HWD_ROOM + "/river",
            "east"   : HWD_ROOM + "/trail2",
     ]) );
  SetInventory( ([
            HWD_NPC + "/squirrel" : 1,
            HWD_NPC + "/deermouse" : 1,       
     ]) );
  SetSmell( ([
    "default" : "The area smells of leaves and moss.",
    ]) );
  SetListen( ([
            "default" : "The sounds of "
                    "rushing water can be heard in the distance.",
     ]) );

 }


/* Approved by Amelia on Sun Sep 14 16:33:15 1997. */
