#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("a soggy swamp");
  SetLong( "Filthy water swirls a couple of feet deep around your legs and "
           "your feet are buried up to the ankles in a slimy mud that "
           "occasionally bubbles off a whiff of noxious gas.  The terrain "
           "gets better to the north where the land rises towards a cliff in "
           "distance.   Any other direction that you might decide to travel "
           "though is just more of the mud and water that you find here." );

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

  SetExits( ([ "west" : GWONISH + "room/swamp3",
               "north" : GWONISH + "room/swamp1",
               "southwest" : GWONISH + "room/swamp4",
               "southeast" : GWONISH + "room/swamp5"]) );

  SetInventory(([GWONISH + "npc/r_lizardman" : CheckNPC(4),
                 GWONISH + "npc/r_swamp" : random(4)]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("north, west, southwest, southeast");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

