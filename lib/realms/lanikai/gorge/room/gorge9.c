 //Lanikai@Haven
//6-21-09
#include <lib.h>
#include <domains.h>
#include "../gorge.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([  
    "south"      : "gorge8",
    "west"       : "mountain1",
    
    ]) );
  SetShort("an ancient gorge");
  SetLong(
    "The gorge follows the footprint of a long-ago dried up riverbed. "
    "Uneven stones and loose pebbles make up the path, but the rockfalls "
    "give way to the side of a solid mountain."
    
    );
  SetSmell("The aroma of chicory, mallow, and dittany hangs in the air.");
  SetListen("A low wind blows through the gorge."); 
  SetItems( ([
            ({"riverbed"}) :
            "The dried up remains of an old river. ",
            ({"stones"}) :
            "These stones are worn smooth by years of water and wind. ",
            ({"pebbles"}) :
            "Smooth pebbles broken off of larger rocks over the years. ",
            ({"rockfall"}) :
            "Less loose than the rest of the area, they seem to form the face of a mountain. ",
	  
                        
    ]) );
  SetInventory( ([
    GORGE_NPC + "vulture":2,
    GORGE_NPC + "owl":1,
  ]) );
}
