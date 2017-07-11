/* Ogre Lair, Estergrym
   Kairehn (17/01/2008) */

#include <lib.h>
#include "../ogrelair.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(30);
  SetShort("a path through some trees");
  SetExits( ([  "northwest" : LAIR_ROOMS + "path2",
                "east" : TOWORLD,  ]) );
  SetSmell( ([ "default" : "The cold air is clean and refreshing.", ]) );
  SetListen( ([ "default" : "The surrounding trees rustle in the wind." ]) );
  SetLong("This small path leads through a dense patch of snow-covered trees. "
          "To the east, the path merges with the North Road. The trees seem "
          "to open up to a clearing in the distance to the northwest, where "
          "the ground rises to form a small hill. To one side of the path "
          "lies a small bone, perhaps that of an animal.");
  SetItems( ([ 
    "trees" : "The snow-covered trees rustle in the wind.",
    "path" : "The small path leads through the trees to the east "
             "and northwest.",
    "clearing" : "The clearing lies to the northwest, and is barely "
                 "visible from here.",
    ({ "ground", "hill" }) : "The ground rises to the northwest, "
                             "resulting in a clearing.",
    "bone" : "The bone looks like it used to be part of an animal.",
  ]) );
  SetItemAdjectives( ([ 
    "trees" : "snow-covered",
    "path" : "small",
    "hill" : "small",
  ]) );
}
