#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;
int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("a small channel");
  SetLong( "The mud here is much drier with only a small trickle of water "
           "flowing through a very small channel from the northeast." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flecks of rotting vegetation "
                       "speckle the surface.",
               "water" : "A thin trickle of water flows through a tiny "
                         "channel from pool to pool of stagnant water.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "trees" : "Weepy thin limbed trees droop into the waters of "
                         "the swamp.",
               "channel" : "Water flows down a thin channel from the "
                           "northeast.",
               "channels" : "Small channels weave their way everywhere "
                            "through the trees and mud of the swamp.",
               "shells" : "Shells, smaller than a pixie's fingernail, are "
                          "stirred into the mix of decaying matter and "
                          "mud."]) );

  SetExits( ([ "west" : GWONISH + "room/swamp5",
               "northeast" : GWONISH + "room/swamp7"]) );

  SetInventory(([GWONISH + "npc/r_lizardman" : CheckNPC(4),
                 GWONISH + "npc/r_swamp" : random(3)]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("west, northeast");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

