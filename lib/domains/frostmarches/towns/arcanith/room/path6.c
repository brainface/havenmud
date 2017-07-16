/* Foot of the mountain */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail towards the mountain");
  SetClimate("arctic");
  
  SetExits( ([
     "north"     : ROOM "/path7",
     "southwest" : ROOM "/path5",
  ]) );

  SetDayLong("The small trail continues toward the mountain.  The mountain "
             "fills the sky before you.  The mountain climbs steeply into "
             "sky.  Small evergreens hang upon the mountain.  The silver "
             "glow is partially blocked by the plateau.");

  SetNightLong("The trail continues its trek trough the night.  Small trees "
               "and a layer of snow can be seen covering the lower part of "
               "the mountain.  A silver glow outlines a mountain plateau.");
 
  SetItems( ([
    ({ "small trail", "trail", "path" })  :
       "The trail winds itself throught the tundra.  The trail leads from "
       "the mountain to the unknown.",
    ({ "dark", "darkness" })  :
       "The darkness covers everything like a blanket.",
    ({ "mountain", "lower part of the mountain" })   :
       "The mountain fills the sky to the north.  It looms over the land.  "
       "There seems to be no peak to the mountain, because clouds cover its "
       "peak.  There is a silver glow from a plateau on the mountain.",
    ({ "plateau"  })  :
       "A cold silver glow shines from the plateau.",
    ({ "cold silver glow", "silver glow", "cold glow", "glow",
       "strange silvery glow", "strange glow", "silvery glow" })  :
       "A cold light shines from the plateau.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells fresh and clean.  The scent of pine "
                 "is strong here.",
  ]) );
 
  SetListen( ([
    "default"  : "The roar of the wind is lessened slightly by the mountain.",
  ]) );

}
