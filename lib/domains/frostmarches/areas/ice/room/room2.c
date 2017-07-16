#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a patch of snow");
SetClimate("arctic");
  SetLong("The small remains of a snowstorm cover this "
    "cobblestone road, and patches of ice litter the area.  "
    "Clouds cover the skies to the north, while to the south, the "
    "area remains clear and warm.");
  SetObviousExits("north, south");
  SetItems( ([ ({ "cobblestone road", "snowy remains", "remains", "patch",
      "road", "patches", "patches of ice", "ice", "small remains"}):
      "Patches of snow and ice cover the road.",
      ({ "area" }): (: GetLong :),
      ({ "snowstorm", "storm", "skies", "clouds", "cloud", "storm cloud"}):
      "Clouds to the north threaten to bury the area with snow, but "
      "the area around here seems safe for the moment."]) );
  SetExits( ([ "north" : ICE_ROOM + "/room3.c",
      "south": ICE_ROOM + "/room1.c"]) );
}


/* Approved by Balishae on Sat Oct  4 23:06:16 1997. */
