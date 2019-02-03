#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("at the top of a cliff");
  SetLong( "The road here takes advantage of the sloping terrain to start a "
           "series of switchbacks leading down the cliff.  The trees here "
           "have been thinned so that the view over the cliff is excellent." );

  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  It "
                        "descends the cliff in a series of switchbacks.",
               "switchbacks" : "The switchbacks descend the cliff in a series "
                               "of ramps.",
               ({"trees", "forest"}) : "The trees stretch high into the sky "
                         "all around.  Many have been cut down to make room "
                         "for the switchbacks leading down the cliff.",
               "roots" : "Many of the roots dangle over the edge of the "
                         "cliff, perhaps you could work your way down "
                         "through them to scale down the cliff.",
               "cliff" : "The cliff is a but part of long palisades.  The "
                         "view here is quite spectacular with a gigantic "
                         "swamp starting some two hundred feet beneath you "
                         "and what appears to be a very large body of water "
                         "further to the west.",
               "palisades" : "The palisades stretch far to the southeast "
                             "growing taller the further south they are.  "
                             "They continue on north from here until they "
                             "turn west and slowly slope down to the sea.",
               "swamp" : "A huge dark swamp that extends far to the south, "
                         "begins beneath you.",
               ({"sea", "water","body of water"}) :
                        "Fog shrouds much of what appears to be a gigantic "
                        "body of water."]) );

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(4),
                 GWONISH + "npc/r_animal" : random(3)]));

  SetSmell( ([ "default" : "The natural decay of the forest spices the air "
                           "pleasantly."]) );
  SetListen( ([ "default" : "A light breeze stirs the leaves around you."]) );
  SetObviousExits("southeast, southwest");

  SetExits( ([ "southwest" : GWONISH + "room/path7",
               "southeast" : GWONISH + "room/path5" ]) );
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

