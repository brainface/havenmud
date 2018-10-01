//  The center of the third level.
//  The Ring of Magic. Portia   1-9-99
//  Changed from Ring of Magic to Market Shops
//  by Alessandra 2009 

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetClimate("underground");
  SetShort("the center of a courtyard");  
  SetLong(
    "The huge obsidian staircase comes to rest in a large circular "
    "area, which is partially enclosed by a rounded half-wall, thus "
    "creating the courtyard. Soft moss covers the ground here, and some "
    "type of clinging vines climb and partly cover the wall. Curved obsidian "
    "benches nestle in with the vines and outline the center of the courtyard. "
    "There is only one path here which leads to an archway entrance to the "
    "marketplace. Small lanterns rest on the ground near the benches, causing "
    "the mossy floor to shimmer with a greenish glow."
    );
  SetListen( ([
    "default" : "Many voices plying wares can be heard in all directions.",
    ]) );
  SetSmell( ([
    "default" : "Scents ranging from freshly baked bread to the crisp smell "
    	"of new clothing mingle in the air.",
    ]) );
  SetItems( ([
    ({"area", "courtyard"}) : (:GetLong:),
    ({"staircase", "stairs", "stair"}) : 
    	"The obsidian staircase leads to the upper levels of Malveillant.",
    ({"path"}) : 
    	"The path is covered with moss and leads north to an open archway "
    	"into the Marketplace.",
    ({"archway", "arch"}) : 
    	"The archway is carved of the same smooth obsidian used in most of "
      "Malveillant. Vines wrap around and drape festively from the arch.",
    ({"walls", "wall"}) : 
    	"This is a half-wall, carved from obsidian, which circles the "
      "courtyard and gives a nice view of the bustling market that "
      "encompasses its outside.",
    ({"ground", "floor"}) : 
    	"The ground is covered in soft moss and overgrown clinging vines.",
    ({"moss"}) : 
    	"The moss is soft and varies from a pale to dark green.",
    ({"lantern", "lanterns"}) : 
    	"The metal lanterns rest on the ground near the benches, the "
      "light making the pale green moss shimmer.",
    ({"benches", "bench"}) :
    	"These obsidian benches are curved and nestle nicely against the "
    	"walls amidst vines and moss.",
    ({"vines", "vine"}) :
    	"Small vines cling to the ground and walls, climbing over the wall "
    	"and spilling into the marketplace.",
    ({"marketplace", "market", "shop", "shops", "vendor", "vendors"}) :
    	"Over the circular wall, the busy marketplace is filled with shops and "
    	"vendors, plying their wares to the citizens of Malveillant.",
    ({"obsidian"}) :
    	"A stone used frequently by the dark-elves, jet black in color and "
    	"smooth and cool to the touch.",
    ]) );
  SetItemAdjectives( ([
    "courtyard" : ({"circular", "center"}),
    "staircase" : ({"huge", "obsidian"}),
    "path" : ({"only", "one", "north"}),
    "archway" : ({"carved", "obsidian"}),
    "walls" : ({"half", "circular", "obsidian", "carved", "rounded"}),
    "ground" : ({"mossy", "covered", "moss-covered"}),
    "moss" : ({"soft", "green", "pale", "dark"}),
    "benches" : ({"curved", "nestled", "obsidian"}),
    "vines" : ({"climbing", "clinging", "draping", "overgrown"}),
    "marketplace" : ({"busy"}),
    "obsidian" : ({"black", "smooth"}),
    "lantern" : ({"metal", "small"}),
    ]) );
  SetInventory( ([
    ]) );
  SetEnters( ([
     "archway" : MAL_ROOMS3 + "marketentrance",
     "market" : MAL_ROOMS3 + "marketentrance",
     "marketplace" : MAL_ROOMS3 + "marketentrance",
    ]) );
  SetExits( ([
    "up" : MAL_ROOMS3 + "stair3",
    ]) );

}

