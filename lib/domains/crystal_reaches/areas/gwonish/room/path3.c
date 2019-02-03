#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("a road through the trees");
  SetLong( "The trees are quite thick all around the road, but the appear "
           "to thin somewhat to the northeast along this very same road.  "
           "The road makes a gradual turn here leading to the west and "
           "northeast." );
  
  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  "
                        "However, an occasional tree root has cause the "
                        "surface to crumble where it has poked through.",
               ({"trees", "forest"}) : "The trees stretch high into the sky "
                         "all around.  They are remarkable thick here and "
                         "appear to get more so to the west.", 
               ({"root","roots"}) : "The roots have over time forced their "
                                    "way up through the surface of the road."
                                    ]) );
  
  SetExits( ([ "west" : GWONISH + "room/path4",
               "northeast" : GWONISH + "room/path2" ]) );
  
  SetSmell( ([ "default" : "The natural decay of the forest spices the air "
                           "pleasantly."]) );
  SetListen( ([ "default" : "A light breeze stirs the leaves around you."]) );
  SetObviousExits("west, northeast");
  
  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(2),
                 GWONISH + "npc/r_animal" : random(2)]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}
