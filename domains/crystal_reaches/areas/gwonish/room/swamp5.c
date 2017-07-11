#include <lib.h>
#include <domains.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("a soggy swamp");
  SetLong( "The water here swirls around a bit but has a generally "
           "western flow as it weaves around the trees and mudbars of the "
           "swamp." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flecks of rotting vegetation "
                       "speckle the surface.",
               "water" : "Murky water swirls around in chaotic patterns.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               ({"mudbar","mudbars"}) : "Water swirls around these up raised "
                         "mounds of mud and roots.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "trees" : "Weepy thin limbed trees droop into the waters of "
                         "the swamp.",
               "shells" : "Shells, smaller than a pixie's fingernail, are "
                          "stirred into the mix of decaying matter and "
                          "mud."]) );

  SetExits( ([ "northwest" : GWONISH + "room/swamp2",
               "east" : GWONISH + "room/swamp6",
               "southeast" : CRYSTAL_REACHES_TOWNS "gwonish/room/gw12",
               ]) );

  SetInventory(([GWONISH + "npc/r_lizardman" : CheckNPC(3)+1,
                 GWONISH + "npc/r_swamp" : random(4)]));


  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("east, northwest, southeast");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

