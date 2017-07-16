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
    "the face of Shatadru Mountain. Here a steep drop leads "
    "down to the base of the mountain and the path continues "
    "northwesterly up to the lofty summit high above."
  );
  SetItems( ([
    ({ "snow", "slope" }) : 
    "The little snow that stands here is dry and sparsely "
    "laid across the rocks.",
    ({ "path", "face" }) : 
    "The winding path leads towards the mountain peak. ",
    ({ "drop" }) :
    "Falling from this height would be quite unfortunate. ",
    ({ "summit" }) :
    "The mountain peak is far from here, obscured by clouds.",
  ]) );
  SetItemAdjectives( ([
    "snow" : ({ "dry" }),
    "path" : ({ "winding" }),
    "drop" : ({ "steep" }),
    "summit" : ({ "lofty" }),
  ]) );
  SetExits( ([
    "northwest" : MTN_ROOM "/mtn14",
    "down" : MTN_ROOM "/mtn12",
  ]) );
  SetInventory( ([ 
    MTN_NPC "/yeti2" : 1,
  ]) );
}
