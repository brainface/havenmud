/*                                                                   */
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File name: path3.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetNightLight(20);
  SetDayLight(20);
  SetShort("just south of the entrance to a dark pyramid");
  SetLong("The path stops here at the entrance of a huge and "
          "dark pyramid. A strong evil energy can be felt "
          "emanating from the walls of the pyramid. The "
          "path goes north inside of the pyramid and back "
          "to the southeast."
         );
  SetItems( ([ 
               ({"snow"}) : "The snow is of an odd white.",
               ({"path"}) : "The path is difficult to follow "
                            "because of the snow."
           ]) );
  SetItemAdjectives( ([
                       "snow" : ({"white"}),
                   ]) );
  SetExits( ([
              "north" : P_ROOM + "/entrance",
              "southeast" : P_ROOM + "/path2"
           ]) );
}