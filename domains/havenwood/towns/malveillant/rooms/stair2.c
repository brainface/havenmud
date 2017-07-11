//  Stairway to the second level.
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
    "the staircase. Continuing down leads to the second level "
    "while up leads back to the first level of Malveillant."
    );
  SetListen( ([
    "default" : "The sounds of the bustling town are muted here.",
    ]) );
  SetSmell( ([
    "default" : "Earthy smells permeate the air here.",
    ]) );
  SetItems( ([
    ({"step", "steps" "staircase", "stair", "stairs"}) : (:GetLong:),
    ({"ground", "floor"}) : 
    	"The stairs are edged in soft moss and overgrown clinging vines.",
    ({"moss"}) : 
    	"The moss is soft and varies from a pale to dark green.",
    ({"vines", "vine"}) :
    	"Small vines cling to the ground and edges of the staircase. ",
    ({"obsidian"}) :
    	"A stone used frequently by the dark-elves, jet black in color and "
    	"smooth and cool to the touch.",
    ]) );
  SetItemAdjectives( ([
    "staircase" : ({"curved", "obsidian", "spiral", "circular"}),
    "ground" : ({"mossy", "edged", "moss-covered"}),
    "moss" : ({"soft", "green", "pale", "dark"}),
    "vines" : ({"climbing", "small", "clinging", "overgrown"}),
    "obsidian" : ({"black", "smooth", "cool"}),
    ]) );
  SetInventory( ([
    ]) );
  SetEnters( ([
    ]) );
  SetExits( ([
    "up" : MAL_ROOMS + "center1",
    "down" : MAL_ROOMS + "center2",
    ]) );

}

