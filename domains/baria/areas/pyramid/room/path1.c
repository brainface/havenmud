/*                                                                   */
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File name: path1.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetNightLight(20);
  SetDayLight(30);
  SetShort("a path west of the Western Wastes road");
  SetLong("The path here is difficult to follow because of the "
          "dense snow. The wind has increased in strength and has "
          "lowered its temperature. There seems to be a path "
          "northwest from here, the path also follows southeast."
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
              "east" : "/domains/world/virtual/frostmarchrd/0,20"
           ]) );
}