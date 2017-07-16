/*  A mountain trail leading to the ruins. */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail up the mountain");
  SetClimate("arctic");
  
  SetExits(  ([
     "north"    : ROOM "/mountain4",
     "south"  : ROOM "/mountain2",
  ]) );

  SetDayLong("The path continues to wind its way along the mountain.  It "
             "leads up the mountain to a plateau, and down the mountain "
             "to the snowy tundra.  The trees have become very scarce, "
             "the tundra is far below.  Oddly there is very little "
             "snow in the surrounding area.");
             

  SetNightLong("The path is illumated slightly by the silver glow from "
               "above.  A plateau lies above this part of the path.  "
               "This area seems isolated and bare.  There are no trees "
               "and very little snow.");

  SetItems( ([
    ({ "small mountain path", "small path", "mountain path", "path", 
       "trail" })   :
       "The small mountain path continues its trek along the mountain.",
    ({ "pine trees", "pine tree", "tree", "trees" })   :
       "There are few trees this high on the mountain.  Pine trees dot the "
       "mountain below.",
    ({ "layer of snow", "snow" })  :
       "The mountain below is covered with a layer of snow.  There is very "
       "little snow in this area or above.",
    ({ "icy tundra", "tundra" })  :
       "The icy tundra is barely visible from this altitude.  The tundra "
       "runs for miles around the mountain.",
    ({ "plateau" })   :
       "A plateau lies half-way above the mountain.  A mysterious silver "
       "glow washes over its edge.",
    ({ "mysterious silver glow", "silver glow", "glow" })  :
       "A mysterious silver glow shines above the plateau.",
  ]) );

  SetSmell( ([
    "default"  :"The smell of pine is replaced by a scent of dirt and dust.",
  ]) );

  SetListen( ([
    "default"  :"The sound of falling rock breaks the silence of the path.",
  ]) );

}
