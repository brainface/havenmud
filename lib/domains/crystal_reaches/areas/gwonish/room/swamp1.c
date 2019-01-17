#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("edge of a swamp");
  SetLong( "Mud sucks at your feet here where the land slopes down into a "
           "damp, stinking mess.  Heat almost seems to radiate from the "
           "swamp to your south.  The trees there are all of tropical "
           "varieties, unlike the evergreens that normally grow here.  "
           "A few can still be seen up the slope to the north on "
           "the other side of the road." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flecks of rotting vegetation "
                       "speckle the surface.",
               "road" : "A few yards north and uphill runs a well kept "
                        "paved road.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               "trees" : "Weepy thin limbed trees droop into the waters of "
                         "the swamp.",
               "shells" : "Shells, smaller than a pixie's fingernail, are "
                          "stirred into the mix of decaying matter and "
                          "mud."]) );

  SetExits( ([ "north" : GWONISH + "room/path9",
               "south" : GWONISH + "room/swamp2"]) );

  SetInventory(([GWONISH + "npc/r_lizardman" : CheckNPC(4),
                 GWONISH + "npc/r_swamp" : random(4)]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

