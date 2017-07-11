/*  Path off of main road. */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("an icy path");
  SetClimate("arctic");
  
  SetExits(  ([
     "east" : ROOM "/path2",
    "west" : "/domains/frostmarches/virtual/frostmarchrd/0,30",
  ]) );
 
  SetDayLong("This small trail heads off into the frozens wastes.  Ice and "
             "snow are the only landmarks you can see in any direction.  "
             "The road is still visible to the west.");

  SetNightLong("The small trail is bearly visible in the night.  The "
               "surrounding area is enveloped by the soft embrace of "
               "the night.  Snow and ice cover the land.");
 
  SetItems( ([
    ({ "small frozen trail", "trail", "small trail", "frozen trail" })  :
       "The small frozen trail weaves throught the snow covered terrain.",
    ({ "frozen wastes", "wastes", "terrain", "area", "surrounding area",
       "land" })  :
       "The terrain is covered in a blanket of ice and snow.",
     ({ "blanket of ice and snow", "blanket of ice", "blanket of snow",
        "snow", "ice", "ice and snow", "hard-packed snow", 
        "patches of ice" })  :
        "Hard-packed snow covers the land for miles.  Patches of ice make "
        "travel dangerous.",
    ({ "landmark", "landmarks" })  :
       "There are no landmarks in the frozen wastes.",
    ({ "road" })  :
       "The road to Keryth is still visible to the west.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells clean, and carries the hint of snow.",
  ]) );
 
  SetListen( ([
    "default"  : "The whispering wind and the crunch of snow are the only "
                 "sounds in the wastes.",
  ]) );
}
