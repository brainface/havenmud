/*  Trail ending at plateau  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail up the mountain");
  SetClimate("arctic");
  
  SetNightLight(20);
  SetExits(  ([
     "north"       : ROOM "/plateau1",
     "south"     : ROOM "/mountain3",
  ]) );

  SetDayLong("The trail looks like a waterfall as it flows over the edge "
             "of the plateau and down the mountain below.  There is very "
             "little in this area besides rocks "
             "and snow.  The trees hang on the mountain below the "
             "treeline.");

  SetNightLong("The silver light bathes this area in its radiance.  The "
               "lip of the plateau is just a small ways up the path.  The "
               "rest of the path winds its way down the mountain.  "
               "Rocks are the only scenery in this area.  No plants grow "
               "here above the treeline.");

  SetItems( ([
    ({ "small path", "waterfall", "path", "trail" })  :
       "The trail continues up to the plateau.  Its end disappears as it "
       "achieves it goal.",
    ({ "lip of the plateau", "plateau", "lip", "large plateau" })  :
       "The large plateau fills the area above the path.  A silver light "
       "washes over the lip of the plateau.",
    ({ "silver light", "silver glow", "light", "glow", "radiance" })  :
       "The silver glow illuminates the sky above.",
    ({ "large rock", "large rocks", "rocks", "rock" })  :
       "Large rocks line the path.  The rocks reach for the sky.",
    ({ "blanket of snow", "snow" })  :
       "A blanket of snow covers the lower end of the mountain.",
    ({ "short pine trees", "short pine tree", "short tree", "short trees",
       "trees", "tree", "treeline", "pine tree", "pine trees" }) :
       "Short pine trees cover the mountain below.  The trees reach the "
       "treeline and go no further.",
  ]) );

  SetSmell( ([
    "default"  : "The smells of dust and decay fill the air.  Strangely, it "
                 "also smells of spring.",
  ]) );

  SetListen( ([
    "default"  : "The area is strangely quiet.",
  ]) );

}
