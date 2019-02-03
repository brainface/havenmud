#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("small clearing");
  SetLong( "The trees are thick enough surrounding this clearing that "
           "there are only two passages in or out.  The trail through the "
           "area seems to support this as well." );
  
  SetItems( ([ ({"passage","passages","trail","trails"}) :
               "The trail curves its way through the clearing exiting north "
               "and northwest.",
               "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.",
               "trees" : "Most of the trees have been cleared here, leaving "
                         "nothing but stumps, but the perimeter looks "
                         "much to thick to adventure beyond.",
               "mudflat" : "The mudflat extends far to the south, but tapers "
                           "off to the north turning back into the swamp "
                           "that dominates the area."]) );
  
  SetExits( ([ "north" : GWONISH + "room/swamp15",
               "northwest" : GWONISH + "room/swamp17"]) );
  
  SetInventory(([GWONISH + "npc/lizardmanelite.c": 4]) );
  
  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("north, northwest");
}
