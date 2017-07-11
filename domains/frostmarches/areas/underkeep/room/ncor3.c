#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("a serpentine corridor");
  SetLong(
    "The corridor seems to flow gradually, almost indiscernably, downwards,"
    " winding its way deep into the bowels of the earth. The air here seems"
    " to be getting slightly hotter, as if it approaches an underwater lava"
    " stream or something. However, there is still no sign of an end to this"
    " sinuous, sloping, slimy place.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    ({"bowel","bowels"}) :
    "The corridor is deep underground.",
       ({"walls", "wall"}) :
    "The walls are sticky to the touch, and are saturated by "
      "some kind of slimy excretion.",
    "air" : "Air is not something that is usually visible.",
    ({"lava","stream"}) :
      "The warm air and gurgle of liquid would suggest one running"
      " parallel to this section of passage.",
    "place" : (:GetLong:), 
    ]) );
  SetItemAdjectives( ([
    "bowel" : "of the earth",
    "lava" : "stream",
    "place" : ({"sinuous","sloping","slimy"}),
    ]) );
  SetSmell( ([
    "default" : 
      "The stench of this place is beyond description.",
    "air" : "The air smells of sulphur here.",
    ]) );
  SetListen( ([
    "default" :
      "The soft gurgle of liquid can be heard through the wall.",
    ({"wall","walls"}) :
      "The soft gurgle of liquid can be heard through the wall.",
    ]) );
  SetExits( ([
    "north" : RNQ_RM + "snakepit.c",
    "south" : RNQ_RM + "ncor2.c",
    ]) );
}
//
// a corridor
// by Ranquest@Haven
//
