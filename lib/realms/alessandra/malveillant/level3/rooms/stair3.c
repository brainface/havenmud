//  Stairway to the third level.
//  by Alessandra 2009 

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetClimate("underground");
  SetShort("a staircase");  
  SetLong(
    "The obsidian staircase curves in a circular pattern that spirals "
    "upwards and downwards, connecting the different levels of "
    "Malveillant. Soft moss and vines trail up and down the edges of "
    "the staircase. Continuing down leads to the third level marketplace "
    "while up leads back to the second level of Malveillant"
    );
  SetListen( ([
    "default" : "The sounds of the bustling town are muted here.",
    ]) );
  SetSmell( ([
    "default" : "The faint aroma of freshly baked bread wafts up from "
    	"the marketplace.",
    ]) );
  SetItems( ([
    ({"step", "steps" "staircase", "stair", "stairs"}) : (:GetLong:),
    ({"ground", "floor"}) : 
    	"The stairs are edged in soft moss and overgrown clinging vines.",
    ({"moss"}) : 
    	"The moss is soft and varies from a pale to dark green.",
    ({"vines", "vine"}) :
    	"Small vines cling to the ground and edges of the staircase. ",
    ({"marketplace", "market", "shop", "shops", "vendor", "vendors"}) :
    	"Over the edge of the circular staircase, the busy marketplace "
    	"can be seen. It is filled with shops and vendors, plying their "
    	"wares to the citizens of Malveillant.",
    ({"obsidian"}) :
    	"A stone used frequently by the dark-elves, jet black in color and "
    	"smooth and cool to the touch.",
    ]) );
  SetItemAdjectives( ([
    "staircase" : ({"curved", "obsidian", "spiral", "circular"}),
    "ground" : ({"mossy", "edged", "moss-covered"}),
    "moss" : ({"soft", "green", "pale", "dark"}),
    "vines" : ({"climbing", "small", "clinging", "overgrown"}),
    "marketplace" : ({"busy", "filled", "third-level"}),
    "obsidian" : ({"black", "smooth", "cool"}),
    ]) );
  SetInventory( ([
    ]) );
  SetEnters( ([
    ]) );
  SetExits( ([
    "up" : MAL_ROOMS + "center2",
    "down" : MAL_ROOMS3 + "center3",
    ]) );

}

