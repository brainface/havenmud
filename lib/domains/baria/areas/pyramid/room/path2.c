/*                                                                   */
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File name: path2.c
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
  SetShort("a cold and dark path on top of a hill");
  SetLong("This part of the path is very dark and cold. The wind is "
          "increasing in strength and is "
          "lowering its temperature. Also, there's something that looks "
          "like a building northwest of here. The path goes northwest "
          "down the hill and to the southeast."
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
              "northwest" : P_ROOM + "/path3",
              "southeast" : P_ROOM + "/path1"
           ]) );
}
