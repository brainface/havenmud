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
    "southeast"       : "gorge6",
    "northwest"       : "gorge8",
    
    ]) );
  SetShort("an ancient gorge");
  SetLong(
    "The gorge follows the footprint of a long-ago dried up riverbed. "
    "Uneven stones and loose pebbles make up the path with rockfalls "
    "looming overhead. A rusty axe is pressed into the ground by a large footprint. "
    
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
            "Rocks hang precariously, looking ready to fall at any moment. ",
	    ({"axe"}) :
            "A common war-axe, this weapon seems rusted and nearly useless now. ",
	    ({"footprint"}) :
            "It seems to have been made by something quite large with 5 toes but doesnt look fresh. ",
                        
    ]) );
  SetInventory( ([
    GORGE_NPC + "partridge":3,
    GORGE_NPC + "krikri":3,
  ]) );
}
