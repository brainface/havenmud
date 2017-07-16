 /*
  * Balishae@Haven
  * 14 Oct 1997
  * Duuk@Haven
  * 19 Sept 2004
  */
  
#include <lib.h>
#include <domains.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("near the entrance to Glimmerdin");
  SetLong(
    "The road ends here near the entrance to a large tunnel. "
    "Set deep in the mountain, the massive stoneworking that "
    "supports it can be seen even from a distance. The tunnel "
    "entrance serves as the first indicator that the city of "
    "the dwarves, Glimmerdin, is in the mountain. Off to the "
    "south, the road leads away from the Crystal Reaches and "
    "into the lower lying areas, while to the north can only "
    "be seen the mountain range."
    );
  SetItems( ([
    ({ "entrance", "tunnel", }) :
        "The tunnel entrance leads deep into Glimmerdin. "
        "Massive stoneworking which can be seen from here holds "
        "the entrance against the elements.",
    ({ "stoneworking", "stone" }) : 
        "Massive arms of stone are hewn and formed from the mountain "
        "in a fashion which could only have been done by dwarves.",
    ({ "mountain", "mountains", "range", "reaches", }) : 
        "The Crystal Reaches rise into the sky, the largest mountain "
        "range of Kailie.",
    ]) );
  SetItemAdjectives( ([
    "entrance" : ({ "large", "tunnel", }),
    "stoneworking" : ({ "massive", "arms", "of", }),
    "mountain" : ({ "crystal", "reaches", "mountain", }),
    ]) );
  SetSmell( ([
    "default" : "A breeze brings a faintly earthy smell from the tunnel.",
    ]) );
  SetListen( ([
    "default" : "Echoes can barely be heard from the tunnel.",
    ]) );
  SetExits( ([ 
    "south" : CRYSTAL_REACHES_VIRTUAL "glimmerdinroad/-12,22",
    "north" : G_ROOM "greatgate",
    ]) );
}