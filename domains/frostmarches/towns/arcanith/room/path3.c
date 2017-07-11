/*  Continuation of road  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("an icy path");
  SetClimate("arctic");
  
  SetExits( ([
     "east" : ROOM "/path4",
     "west" : ROOM "/path2",
  ]) );

  SetDayLong("The lonely trail continues its trek across the frozen tundra.  "
             "To the northeast you see the faint outline of a mountain "
             "rising into the sky.");

  SetNightLong("The dark path continues it trek through the dark, frozen "
               "tundra.  The stars seem to outline the form of a mountain "
               "to the northwest.  It is hard to tell in the darkness.");

  SetItems( ([
    ({ "small frozen trail", "lonely trail", "trail", "dark path", "path",
       "small trail", "frozen trail" })  :
       "The small frozen trail weaves throught the snow-covered terrain.",
    ({ "snow-covered terrain", "wastes", "tundra", "fozen tundra", "terrain",
       "dark tundra", "dark frozen tundra" })  :
       "The terrain is covered in a blanket of ice and snow.  There "
       "appears to be a mountain to the northeast.",
    ({ "dark", "darkness" })  :
       "The darkness covers everything like a blanket.",
    ({ "mountain" })  :
       "There seems to be a mountain rising out of the frozen ground to the "
       "northwest.",
    ({ "frozen ground", "ground", "snow", "blanket of ice and snow",
       "snow", "ice and snow" })  :
       "Snow and ice covers the frozen ground as far as the eye can see.",
    ({ "layer of ice", "ice" })  :
       "A layer of ice covers the snow making it shine in the light.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells fresh and clean.",
  ]) );
 
  SetListen( ([
    "default"  : "The wind continues to moan across the tundra.",
  ]) );
}
