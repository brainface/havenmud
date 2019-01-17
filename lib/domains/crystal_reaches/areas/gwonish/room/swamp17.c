#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("a small rise");
  SetLong( "The small rise is capped by a wide, shallow hole.  A trail leads "
           "southeast through the trees that surround the area.");
  
  SetItems( ([ ({"hole","nest"}) :
               "The shallow hole is lined with grass, leaves, and skins",
               "skins" : "The skins are humanoid in nature.",
               "rise" : "It looks like the earth here has been intentionally "
                        "piled into a mound about six feet high and "
                        "fifteen feet wide.",
               "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.",
               "trees" : "Most of the trees have been cleared here, leaving "
                         "nothing but stumps, but the perimeter looks "
                         "much to thick to adventure beyond.",
               "mudflat" : "The mudflat extends far to the south, but tapers "
                           "off to the north turning back into the swamp "
                           "that dominates the area."]) );
  
  SetExits( ([ "southeast" : GWONISH + "room/swamp16"]) );
  
  //SetInventory(([GWONISH + "npc/lizardmanelite.c": 2]) );
  //SetInventory(([GWONISH + "npc/lizardmancaptain.c": 1]) );

  
  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "It is very quiet here." ]) );
  SetObviousExits("southeast");
}
