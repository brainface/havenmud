#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;


static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("atop a small hill");
  SetLong( "The grass atop this small hill is very well manicured.  "
           "Especially along the gravel path leading into the collumned "
           "building ahead.  The path also leads down to a hazy swamp in the "
           "southeast and perhaps to the palisades beyond." );

  SetItems( ([ "palisades" : "The palisades stretch far to the southeast "
                             "growing taller the further south they are.  "
                             "They curve around to create a boundary to "
                             "the north as well.",
               "swamp" : "A huge dark swamp begins a short distance to the "
                         "southeast.",
               "hill" : "The hill is really just a slight swell in the slope "
                        "that the palisades have become as they slope towards "
                        "the sea.",
               "building" : "This is the first major piece of stonework to "
                            "be found anywhere in the area.  It must be a "
                            "structure of some importance.",
               "sea" : "An enormous amount of fog rolls over the sea, "
                       "restricting your view to a few hundred yards.  "
                       "Perhaps the fog is a result of the strange warmth "
                       "here.",
               "path" : "The gravel path leads from the building on top of "
                        "the hill to the road at the bottom of the hill.",
               "grass" : "Rich green blades of grass are cut evenly all "
                         "across the hill."]) );

  SetExits( ([ "southeast" : GWONISH + "room/path10" ]) );
  SetEnters( ([ "building" : GWONISH + "room/monument" ]) );

  SetInventory(([GWONISH + "npc/groundskeeper": 1]) );

  SetSmell( ([ "default" : "The stagnant rotting smell of the swamp assaults "
                           "is replaced by a fresh cut grass smell."]) );
  SetListen( ([ "default" : "The sound of waves rushing upon the shore "
                            "serves to cover other sound."]) );
  SetObviousExits("southeast, enter building");
}


