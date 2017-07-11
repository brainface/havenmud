
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("east");
  SetShort("a dead end in the cave");
  SetLong(
          "This section in the tunnel is just a dead end. Three walls "
          "all identical bar the path deeper into the cave. Crates and "
          "barrels are destroyed with just bits and pieces of their "
          "former self strewn about the floor.");
  SetInventory( ([ 
                TOWER_OBJ "quill" : 1, 
				  ]) );
  SetExits( ([
            "east"     : TOWER_ROOMS "cave07",
           ]) );
  SetSmell( ([
            "default" : "Something gives off a slight smell of sulfur.",
           ]) );
  SetListen( ([
            "default" : "A faint humming noise is heard."
           ]) );
  SetItems( ([
     "ceiling" : "The ceiling forms downward to form the three walls "
                 "that prevent passage.",
     "walls"   : "The walls have vertical ridges in them, from natural "
                 "cave formation.",
     "crates"  : "They lie in pieces near the west wall.",
     "barrels" : "They rest shattered and broken, barely keeping their "
                 "form and distinction.", 
    ({ "ground", "floor" }) : "It is made of a dark packed clay and "
                               "lines the cavern ground.",
    ({ "crate", "barrel" }) : "It is broken and shattered along the ground.",
	  "clay"   : "Dark packed clay creates the soft ground in this "
	             "cave.",
              ]) );
    SetItemAdjectives( ([
    "crates" : ({ "pieces","bits" }),
    "barrels" : ({ "shattered" }),
    "clay" : ({ "dark","packed" }),
  ]) );
}