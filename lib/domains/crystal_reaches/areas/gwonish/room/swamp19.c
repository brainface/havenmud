#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("a filthy pool");
  SetLong( "The water here deepens into a deep pool filled with the remains "
           "of bloated carcasses trapped by a beaver's dam in the "
           "northwest corner of the pool.  The pool is fed from the south." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.  Small flects of rotting vegitation "
                       "speckle the surface.",
               "water" : "A nasty film covers the surface of the water.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               "roots" : "Knotty roots poke up through the water and weave "
                         "their way through mounds of vegetation and mud.",
               "trees" : "Unlike most of the swamp, the trees here are dead "
                         "and cracking under their own weight.",
               "pool" : "The pool is filled with decaying bodies and body "
                        "parts.",
               ({"dam","beaver dam", "beaver's dam"}) :
                        "The dam appears quite old, it doesn't appear that "
                        "beavers have been here in a long time.",
               ({"carcasses","bodies","body parts"}) :
                        "The bloated body parts once belonged to many "
                        "different types of animals, most of them too "
                        "decayed to identify.  A bloated five fingered hand "
                        "is impossible to miss though.",
               "film" : "The film appears to be made up of different body "
                        "fluids and mounds of hair floating in it."]) );

  SetExits( ([ "northwest" : GWONISH + "room/swamp18",
               "south" : GWONISH + "room/swamp20"]) );

  SetSmell( ([ "default" : "The smell here is much worse than the northern "
                           "areas of the swamp.  A smell not unlike rancid "
                           "meat wafts up from the water."]) );
  SetListen( ([ "default" : "It is quiet except for the occasional bird "
                            "call." ]) );
  SetObviousExits("south, northwest");
}


