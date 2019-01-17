#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("at the top of a cliff");
  SetLong( "Trees block nearly every direction except the road leading "
           "the forest.  It extends to both south and northwest, curving "
           "out of sight in both directions.  To the west, one can barely "
           "make out the edge of a cliff." );
  
  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  ",
               ({"trees", "forest"}) : "The trees stretch high into the sky "
                         "all around.  They are very dense here, right up to "
                         "the edge of the cliff.  Many have roots extending "
                         "into the space beyond the cliff.",
               "roots" : "Many of the roots dangle over the edge of the "
                         "cliff, perhaps you could work your way down "
                         "through them to scale down the cliff.",
               "cliff" : "The cliff is a but part of long palisades.  The "
                         "view here is quite spectacular with a gigantic "
                         "swamp starting some two hundred feet beneath you "
                         "and what appears to be a very large body of water "
                         "further to the west.",
               "palisades" : "The palisades stretch far to the southeast "
                             "growing taller the further south they are.  "
                             "They continue on north from here until they "
                             "turn west and slowly slope down to the sea.",
               "swamp" : "A huge dark swamp that extends far to the south, "
                         "begins beneath you.",
               ({"sea", "water","body of water"}) :
                        "Fog shrouds much of what appears to be a gigantic "
                        "body of water."]) );
  
  SetExits( ([ "northwest" : GWONISH + "room/path6",
               "south" : GWONISH + "room/path4",
               "down" : GWONISH + "room/caveenter.c"]) );
  
  SetSmell( ([ "default" : "The natural decay of the forest spices the air "
                           "pleasantly."]) );
  SetListen( ([ "default" : "A light breeze stirs the leaves around you."]) );
  SetObviousExits("northwest, south");
  
  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(4),
                 GWONISH + "npc/r_animal" : random(3)]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}
