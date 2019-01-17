#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("near the swamp");
  SetLong( "Scrub brush is the dominant foliage here with it slowing "
           "transitioning to tall evergreens in the north near the base "
           "of the cliff.  The road curves north as well as west here, but "
           "a muddy well trampled path slopes down through the brush to the "
           "swamp.  It is uncomfortably warm here compared to the the rest "
           "of the northerly climate around here." );

  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region",
               ({"trees", "forest"}) : "The trees have a decidedly unhealthy "
                        "appearance here. Perhaps the warm damp air is "
                        "affecting them in some way.",
               "cliff" : "The cliff is but a part of long palisades.",
               "palisades" : "The palisades stretch far to the southeast "
                             "growing taller the further south they are.  "
                             "They curve around to create a boundary to "
                             "the north as well.",
               "swamp" : "A huge dark swamp begins a short distance to the "
                         "south.",
               "path" : "The path is muddy and well trampled.  The footprints "
                        "seem a bit odd though.",
               "brush" : "The scrub brush is very dark and nearly leafless.  "
                         "Sharp thorns protrude from many of the branches.",
               "footprints" : "The footprints are obviously not made from "
                              "booted feet.  Indeed they appear larger than "
                              "most humanoid feet, but hold the same general "
                              "shape - except for the claw marks at the ends "
                              "of the four toes."]) );

  SetExits( ([ "north" : GWONISH + "room/path8",
               "west" : GWONISH + "room/path10",
               "south" : GWONISH + "room/swamp1" ]) );

  SetSmell( ([ "default" : "The stagnant rotting smell of a swamp assaults "
                           "you."]) );
  SetListen( ([ "default" : "The air is full of the sounds of birds, "
                            "insects and frogs."]) );
  SetObviousExits("north, west, south");

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(5),
                 GWONISH + "npc/r_lizardman.c": CheckNPC(6),
                 GWONISH + "npc/r_animal" : random(4)]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

