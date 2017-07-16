#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("amidst tidal pools");
  SetLong( "Water flows from pool to pool amidst pockets of trees and "
           "vegetation.  A Short distance across some especially soggy "
           "looking mud, a surf can be seen rolling in from the sea.  South "
           "of here the beginnings of some large rocks can be seen." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flecks of rotting vegetation "
                       "speckle the surface.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               ({"surf","waves"}) :
                         "Somewhat cleaner water is introduced to the area "
                         "by a slow steady pulse from the sea to the west.",
               "sea" : "Waves pulse into the shallows of the swamp.",
               "rocks" : "The ground raises a bit and becomes more rocky.",
               "pools" : "The shallow pools are filled with a briny water "
                         "from the sea."]) );

  SetExits( ([ "northeast" : GWONISH + "room/swamp18",
               "south" : GWONISH + "room/swamp22"]) );

  SetInventory(([GWONISH + "npc/lizardmanguard" : CheckNPC(4),
                 GWONISH + "npc/r_swamp" : random(2)*3]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "It is quiet except for the occasional bird "
                            "call." ]) );
  SetObviousExits("south, northeast");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}


