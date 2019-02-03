#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("at the bottom of a cliff");
  SetLong( "A series of switchbacks scale the enormous cliff that borders "
           "this valley to the north and east.  A road follows the "
           "switchbacks to the summit and continues on to the south as well.  "
           "A short distance to the south the nature of the trees changes "
           "to the scrub brush usually associated with swamps" );
  
  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  It "
                        "descends the cliff in a series of switchbacks.",
               "switchbacks" : "The switchbacks descend the cliff in a series "
                               "of ramps.",
               ({"trees", "forest"}) : "You appear to be in a transitional "
                         "area of the forest.  The trees are beginning to "
                         "switch from a tall evergreen variety to much "
                         "smaller scraglier variety.",
               "cliff" : "The cliff is but a part of long palisades.",
               "palisades" : "The palisades stretch far to the southeast "
                             "growing taller the further south they are.  "
                             "They continue on north from here until they "
                             "turn west and slowly slope down to the sea.",
               "swamp" : "A huge dark swamp begins a short distance to the "
                         "south.",
               ({"sea", "water","body of water"}) :
                        "Fog shrouds much of what appears to be a gigantic "
                        "body of water."]) );
  
  SetExits( ([ "east" : GWONISH + "room/path7",
               "south" : GWONISH + "room/path9" ]) );
  
  
  SetSmell( ([ "default" : "The stagnant rotting smell of a swamp assaults "
                           "you."]) );
  SetListen( ([ "default" : "The air is full of the sounds of birds, "
                            "insects and frogs."]) );
  SetObviousExits("east, south");

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(6),
                 GWONISH + "npc/r_animal" : random(4) + 1]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}
