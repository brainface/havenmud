/* Ogre Lair, Estergrym
   Kairehn (17/01/2008) */

#include <lib.h>
#include "../ogrelair.h"
inherit LIB_ROOM;

int CheckPC();

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(30);
  SetShort("a path through some trees");
  SetExits( ([  "northwest" : LAIR_ROOMS + "clearing1",
  ]) );
  AddExit("southeast", LAIR_ROOMS "path1", (: CheckPC :));
  SetSmell( ([ "default" : "The cold air is clean and refreshing.", ]) );
  SetListen( ([ "default" : "The surrounding trees rustle in the wind." ]) );
  SetLong("This path continues through the trees to both the northwest, where "
          "the trees thin out to form a clearing, and to the southeast. The "
          "ground here is wet and muddy, with large footprints acting as "
          "puddles. There is no obvious sign of wildlife, and it seems as if "
          "the trees surrounding this section of the path are beginning to "
          "decay.");  
  SetItems( ([ 
    "trees" : "The snow-covered trees rustle in the wind.",
    "path" : "The small path leads through the trees to the northwest "
             "and southeast.",
    "clearing" : "The clearing lies to the northwest, and is barely "
                 "visible from here.",
    ({ "ground", }) : "The ground is wet and muddy.",
    "footprints" : "The footprints look like they were made by a "
                   "very large individual.",
    "puddles" : "The footprints are filled with rain water.",
  ]) );
  SetItemAdjectives( ([ 
    "trees" : "snow-covered",
    "path" : "small", 
  ]) );
}

int CheckPC() {
  if (this_player()->id("ogre")) {
    if (this_player()->GetOwner() == "") {
      return 0;
    }
  }  
  return 1;
}
