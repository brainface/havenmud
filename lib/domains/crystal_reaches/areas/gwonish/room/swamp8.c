#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("a small channel");
  SetLong( "Water flows to the northwest through a series of small "
           "channels like this one.  A mudflat begins to the east." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flecks of rotting vegetation "
                       "speckle the surface.",
               "water" : "Water flows northwest through numerous small "
                         "channels.",
               "vegetation" : "Floating in the dark mud the vegetation is "
                              "slowly decaying.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "trees" : "Weepy thin limbed trees droop into the waters of "
                         "the swamp.",
               "channel" : "Water flows down a thin channel to the "
                           "northwest.",
               "channels" : "Small channels weave all over the swamp, "
                            "feeding a larger one to the northwest.",
               "mudflat" : "The terrain changes to a series of mudflats in "
                           "the east."]) );

  SetExits( ([ "northwest" : GWONISH + "room/swamp5",
               "east" :  GWONISH + "room/swamp9"]) );

  SetInventory(([GWONISH + "npc/r_lizardman" : random(3)+2,
                 GWONISH + "npc/r_swamp" : random(4)+1]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("east, northwest");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

