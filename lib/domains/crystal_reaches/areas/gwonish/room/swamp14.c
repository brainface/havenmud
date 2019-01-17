#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("detention area");
  SetLong( "Blood cakes much of the ground here, pooling near the base of "
           "each of the three large trees here.  Connected to each of those "
           "trees are sturdy chains with cuffs at the ends." );

  SetItems( ([ "mud" : "Dried blood is spattered over much of the dark mud.",
               "blood" : "Dried blood covers the ground here staining it a "
                         "red-brown color.",
               "trees" : "The three trees here are spattered with blood "
                         "and scared by chains that were nailed to their "
                         "trunks long ago.",
               "chains" : "The thick chains are covered in blood, but "
                          "not a speck of corrosion can be found along their "
                          "length.",
               "mudflat" : "The mudflat extends far to the south, but tapers "
                           "off to the north turning back into the swamp "
                           "that dominates the area."]) );

  SetExits( ([ "north" : GWONISH + "room/swamp13"]) );

  SetInventory(([GWONISH + "npc/lizardmanguard.c": 2]) );
  SetInventory(([GWONISH + "npc/prisoner.c": 1]));
  if(!random(20))
    SetInventory(([GWONISH + "npc/r_swamp.c": (random(3)+1)]) );

  SetSmell( ([ "default" : "The reak of rotting flesh and blood fills the "
                           "area."]) );
  SetListen( ([ "default" : "It is very quiet here." ]) );
  SetObviousExits("north");
}

