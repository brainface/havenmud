/*  The foot hills of the mountian. */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail up the mountain");
  SetClimate("arctic");
  
  SetExits(  ([
     "north"    : ROOM "/mountain1",
     "south" : ROOM "/path6",
  ]) );
 
  SetDayLong("The trail begins at the foot of the mountain and disappears "
             "into the frozen tundra.   The mountain "
             "rises above the land, covering it in shadows.  Small pine "
             "trees strive to survive in the harsh terrain.  The glow is "
             "is partally concealed by the plateau.");

  SetNightLong("The trail begins at the foot of the mountain and disappears "
               "into the dark tundra.  The stars "
               "are blocked by the towering mountain.  Small pine trees "
               "hide in the night.  High upon the "
               "mountain, the silver glow washes over the edge of the "
               "plateau.");
 
  SetItems( ([
    ({ "small trail", "trail", "path" })  :
       "The small trail runs from the frozen tundra up the mountain.",
    ({ "towering mountain", "dark mountain", "mountain", "steep mountain" }) :
       "The mountain towers over the frozen tundra.  It looms "
       "above the land, partially concealing the sky.",
    ({ "frozen tundra", "tundra", "land" })  :
       "The frozen tundra stretches as far as the eye can see.  The only "
       "break is a towering mountain.",
    ({ "small stunted pine trees", "small pine trees", "stunted pine trees",
       "small stunted pine tree", "small pine tree", "stunted pine tree",
       "pine trees", "pine tree", "trees", "tree", "evergreens", 
       "evergreen"  })    :
       "Small stunted pine trees and evergreens cling to the steep mountain.",
    ({ "silver glow", "glow" })   :
       "The silver glow shines above the plateau.  Its source is not "
       "visible from here.",
    ({ "unknown source", "source" })  :
       "The source of the glow is not visible at this angle.",
    ({ "mountain plateau", "edge of the plateau", "plateau" })  :
       "The plateau lies halfway up the mountain.  A silver glow radiates "
       "from an unknow source.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells of dirt and stone.  The smell of pine "
                 "hangs heavy in the air.",
  ]) );
 
  SetListen( ([
    "default"  : "The clicking of falling rocks fills the air.",
  ]) );
}
