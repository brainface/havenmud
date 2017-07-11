#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("a bone pile");
  SetLong( "Bones are tossed all around the area, scattered along the "
           "mudbanks that run beside the stream.  A foul smelling pool lays "
           "north of here, and the south is boundaried by a thick sucking "
           "mud." );

  SetItems( ([ ({"mud","mudbanks"}) :
                       "The mud to the south takes on a much different "
                       "appearance from the dark mud elsewhere in the "
                       "swamp.  It is much lighter and seems to be more "
                       "loosely bound together.",
               "water" : "The water occasionally dislodges a bone or body "
                         "part and floats it away towards the pool.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "trees" : "The trees stop where the lighter colored mud "
                         "begins.",
               "pool" : "The pool is filled with decaying bodies and body "
                        "parts.",
               ({"carcasses","bodies","body parts", "bones"}) :
                        "The bloated body parts and bones once belonged "
                        "to many different types of animals, most of them "
                        "too decayed to identify.",
               "film" : "The film appears to be made up of different body "
                        "fluids and mounds of hair floating in it."]) );

  SetExits( ([ "north" : GWONISH + "room/swamp19"]) );

  SetInventory(([GWONISH + "npc/r_swamp.c": (random(3)+1)]) );

  SetSmell( ([ "default" : "The smell here is much worse than the northern "
                           "areas of the swamp.  A smell not unlike rancid "
                           "meat wafts up from the water."]) );
  SetListen( ([ "default" : "It is quiet except for the occasional bird "
                            "call." ]) );
  SetObviousExits("north");
}


