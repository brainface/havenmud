#include <lib.h>
#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("a mudbar");
  SetLong( "The land here is a bit drier as it is higher than most of "
           "the surrounding area.  The water swirling around the mudbar "
           "seems to be flowing west until it vanishes into a steady flow "
           "of waves breaking into the shallows at the edge of the swamp.  "
           "The water continues back to the south and east swirling around "
           "numerous smaller mudbars and sickly looking trees." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flecks of rotting vegetation "
                       "speckle the surface.",
               "water" : "Murky water swirls around in chaotic patterns.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               "trees" : "Weepy thin limbed trees droop into the waters of "
                         "the swamp.",
               "shells" : "Shells, smaller than a pixie's fingernail, are "
                          "stirred into the mix of decaying matter and "
                          "mud.",
               "cliff" : "A series of cliffs hide the horizon to the north "
                         "and south.",
               ({"mudbar","mudbars"}) : "Water swirls around these up raised "
                         "mounds of mud and roots.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "waves" : "Somewhat cleaner water is introduced to the area "
                         "by a slow steady pulse from the sea to the west.",
               "sea" : "Waves pulse into the shallows of the swamp."]) );

  SetExits( ([ "east" : GWONISH + "room/swamp2"]) );


  SetInventory ( ([
    GWONISH + "npc/r_lizardman" : CheckNPC(4),
    GWONISH + "obj/bamboo_grove" : 1,
                 GWONISH + "npc/r_swamp" : random(4)]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The soft whisper of waves breaking in the "
                            "distance is occasionally interrupted by a low "
                            "rolling rumble from deeper in the swamp" ]) );
  SetObviousExits("east");
}


int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

