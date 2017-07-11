#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("at the top of a cliff");
  SetLong( "The road makes an abrupt turn here going both north and east.  "
           "Upon closer inspection, the reason for the turn is the high "
           "cliff directly to the west.  The trees go right up to the edge, "
           "with many of them dangling roots over the side." );
  
  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  ",
               ({"trees", "forest"}) : "The trees stretch high into the sky "
                         "all around.  They are very dense here right up to "
                         "the edge of the cliff.",
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
  
  SetExits( ([ "north" : GWONISH + "room/path5",
               "east" : GWONISH + "room/path3",
               "down" : GWONISH + "room/deadend.c"]) );
  
  SetSmell( ([ "default" : "The natural decay of the forest spices the air "
                           "pleasantly."]) );
  SetListen( ([ "default" : "A light breeze stirs the leaves around you."]) );
  SetObviousExits("north, east");
  
  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(3),
                 GWONISH + "npc/r_animal" : random(2)]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}
