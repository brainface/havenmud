#include <lib.h>
#include <domains.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("a soggy swamp");
  SetLong( "The water flowing from the southeast is especially disgusting.  "
           "It churns in with the other flows, creating a nasty brown foam "
           "that sticks to everything it comes in contact with.  Most of the "
           "trees here have died and are slowly rotting away." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flecks of rotting vegetation "
                       "speckle the surface.",
               "water" : "The water of the swamp is despoiled by a stream of "
                         "pollution coming from the southwest",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "trees" : "Unlike most of the swamp, the trees here are dead "
                         "and cracking under their own weight."]) );

  SetExits( ([ "northwest" : GWONISH + "room/swamp4",
               "southeast" : CRYSTAL_REACHES_TOWNS "gwonish/room/gw09",
               "southwest" : GWONISH + "room/swamp21"]) );

  SetInventory(([GWONISH + "npc/r_lizardman" : CheckNPC(5),
                 GWONISH + "npc/r_swamp" : random(4)]));

  SetSmell( ([ "default" : "The smell here is much worse than the northern "
                           "areas of the swamp.  A smell not unlike rancid "
                           "meat wafts up from the water.",
               "foam" : "The foam is truly disgusting, it seems to be where "
                        "the rancid meat smell is coming from."]) );
  SetListen( ([ "default" : "It is quiet except for the occasional bird "
                            "call." ]) );
  SetObviousExits("northwest, southeast, southwest");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

