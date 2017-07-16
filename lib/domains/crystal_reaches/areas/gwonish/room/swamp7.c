#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("base of a cliff");
  SetLong( "A thin trickle of water flows out of the base of a tall cliff "
           "to the east.  The mud of the swamp starts a few feet from the "
           "base and the water flows down into a channel to the "
           "southwest." );

  SetItems( ([ "mud" : "Mostly dried and caked near the base of the cliff, "
                       "the mud gets damper and even soggy to the south"
                       "west.",
               "water" : "A thin trickle of water flows from tiny cracks "
                         "at the base of the cliff.",
               "vegetation" : "Floating in the dark mud the vegetation is "
                              "slowly decaying.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "trees" : "Weepy thin limbed trees droop into the waters of "
                         "the swamp.",
               "channel" : "Water flows down a thin channel from the "
                           "northeast.",
               "cliff" : "Rock and mud tower above you in a series of cliffs "
                         "making up the great palisades that ring most of "
                         "the area.",
               "cracks" : "Tiny cracks riddle the cliff.  Many have moisture "
                          "flowing out to stream into a channel at the base "
                          "of the cliff.",
               "palisades" : "The series of cliffs extend far to the south "
                             "and wrap around to the west in the north as "
                             "well."]) );

  SetExits( ([ "southwest" : GWONISH + "room/swamp6"]) );


  SetInventory(([GWONISH + "npc/r_lizardman" : CheckNPC(2),
                 GWONISH + "npc/r_swamp" : random(4)]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("southwest");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

