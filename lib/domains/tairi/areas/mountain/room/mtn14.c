//Selket@Haven
//2006

#include <lib.h>
#include "../mtn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("on a steep path up the side of Shatadru Mountain");
  SetLong(
    "The wind flutters dry snow over the winding path along "
    "the face of Shatadru Mountain. Here the path leads gently "
    "southeasterly to the base of the mountain and "
    "northwesterly up to the lofty summit high above. "
  );
  SetItems( ([
    ({ "snow", "slope" }) : 
    "The little snow that stands here is dry and sparsely "
    "laid across the rocks.",
    ({ "path", "face" }) : 
    "The winding path leads towards the mountain peak. ",
    ({ "summit" }) :
    "The mountain peak is far from here, obscured by clouds.",
  ]) );
  SetItemAdjectives( ([
    "snow" : ({ "dry" }),
    "path" : ({ "winding" }),
    "summit" : ({ "lofty" }),
  ]) );
  SetExits( ([
    "northwest" : MTN_ROOM "/mtn15",
    "southeast" : MTN_ROOM "/mtn13",
  ]) );
  SetInventory( ([ 
    MTN_NPC "/goat2" : 3,
  ]) );
}
