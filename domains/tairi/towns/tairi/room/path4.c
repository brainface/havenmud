#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "northeast" : "path8",
    "southwest" : "path1",
    ]) );
  SetShort("a path outside a building");
  SetLong("The path continues to the northeast and southwest here, "
          "with the northeast leading further into town and the "
          "southwest heading back towards the Tai mountain range. "
          "Sitting by the side of the path is a small wooden building "
          "with paper-looking walls.");
  SetItems( ([
    ({ "town", "Tairi" }) :
    				"The town of Tairi is off to the northwest.",
    ({ "building", "inn"}) : 
    	      "This squat building has a wooden frame and thin paper looking "
    	      "walls. There is a chimney rising from its center with smoke "
    	      "billowing forth constantly.",
    "smoke"    : "The smoke from the chimney is a thick black.",
    "chimney"  : "The stone chimney vents smoke into the air.",
    ({ "path", "road" })  : 
             "This beaten dirt path is a road that travels on the outskirts "
             "of town.",
    ({ "wall", "walls" }) : 
    	       "The walls of the building are a thin paper substance which "
    	       "seems oddly heavy.",
    ({ "range", "mountain", "mountains" }) :
    	       "In the southwest the Tai mountain range can be seen protecting "
    	       "the town of Tairi.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "small", "wooden" }),
    "wall"     : ({ "thin", "paper", "looking" }),
    "range"    : ({ "Tai", "tai", "mountain" }),
    "mountain" : ({ "Tai", "tai" }),
    ]) );
  SetEnters( ([
    "building" : TAI_RI_ROOM + "inn",
    ]) );
  SetSmell( ([
    "default" : "The scent of food cooking hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "The town is quiet and peaceful.",
    ]) );
  SetInventory( ([
  ]) );
}
