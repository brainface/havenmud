/*  Continuation of road  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("an icy path");
  SetClimate("arctic");
  
  SetExits( ([
     "east" : ROOM "/path3",
     "west" : ROOM "/path1",
  ]) );

  SetDayLong("The trail continues to cut a path through the frozen wastes.  "
             "There seems to be nothing for miles, with the exception of "
             "snow, ice and this trail.  The ends of the trail disappear "
             "into their respective horizions.");

  SetNightLong("The is barely any indication that there is a path here.  "
               "The darkness begins to feel oppressive.  The night seems "
               "to cause every crunch of snow to be accentuated.");

  SetItems( ([
    ({ "small frozen trail", "small trail", "frozen trail", "trail",
       "path" })  :
       "The small frozen trail weaves throught the snow-covered terrain.",
    ({ "snow-covered terrain", "wastes", "frozen wastes", "terrain" })  :
       "A cool wind blows across the snow-covered terrrain.",
    ({ "dark", "darkness" })  :
       "The darkness covers everything like a blanket.",
    ({ "snow" })   :
       "The snow covers everthing for miles.",
    ({ "cold ice", "ice" })  :
       "Cold ice forms a hard shell over much of the terrain.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells clean, and carries the hint of snow.",
  ]) );
 
  SetListen( ([
    "default"  : "The whispering wind and the crunch of snow are the only " 
                 "sounds in the wastes.",
  ]) );
}
