#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("at the base of some rocks");
  SetLong( "The ground here is gradually becoming more solid, at points "
           "even rocky.  A trail has been chiseled up the side of the largest "
           "pile of rocks and over the top, out of sight.  The land lowers "
           "to the north into a series of tidal pools." );

  SetItems( ([ "mud" : "The mud here has almost disappeared and became a "
                       "healthy soil amidst the rocks.",
               "water" : "Water washes up from the sea and spills over into "
                         "the many tidal pools of the area.",
               "trail" : "The trail leads from the tidal pools in the north "
                         "to up into the rocks until it can no longer be "
                         "seen.",
               "rocks" : "The rocks are grey and weatherbeaten with age.  "
                         "A pile large enough to be considered a hill begins "
                         "to the south with a trail leading up and around  "
                         "to the west.",
               "vegetation" : "Floating in the dark mud that vegetation is "
                              "slowly decaying.  Mixed in with it is an "
                              "occasional tiny shell.",
               ({"surf","waves"}) :
                         "Somewhat cleaner water is introduced to the area "
                         "by a slow steady pulse from the sea to the west.",
               "sea" : "Waves pulse into the shallows of the swamp.",
               "pools" : "The shallow pools are filled with a briny water "
                         "from the sea."]) );

  SetExits( ([ "north" : GWONISH + "room/swamp21",
               "west" : GWONISH + "room/swamp23"]) );

  SetInventory(([GWONISH + "npc/lizardmanguard" : 2,
                 GWONISH + "npc/r_swamp" : random(2)*2]));

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "It is quiet except for the occasional bird "
                            "call." ]) );
  SetObviousExits("north, west");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}


