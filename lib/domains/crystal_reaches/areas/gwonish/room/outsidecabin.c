#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("outside of a cabin");
  SetLong( "Smoke spirals up from the old cabin's chimney that rests at the "
           "north end of the path.  A short distance to the south a well "
           "built road intersects with the path." );

  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  "
                        "However, grass and small weeds are starting to "
                        "grow over much of the road.",
               "cabin" : "Rough hewn logs make up a majority of the cabin's "
                         "structure.  It looked to have weathered many years, "
                         "especially the chimney that belches smoke into the "
                         "air.  A sturdy looking door covers the only "
                         "entrance.",
               "path" : "Strangely, the path is in much better care than "
                        "the road, in spite of its dirt composition.",
               "smoke" : "Smoke spirals up from a hole in the cabin's roof "
                         "and dissipates.",
               "chimney" : "Smoke spirals away from the weather beaten "
                           "chimney."]) );

  SetExits( ([ "south" : GWONISH + "room/path2"]) );

  SetEnters( ([ "cabin" : GWONISH + "room/cabin"]) );

  SetDoor("cabin", GWONISH + "room/cabindoor");

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(5),
                 GWONISH + "npc/r_animal" : random(3)]));

  SetSmell( ([ "default" : "The open air of the plains mixes with a fresh "
               "cut wood smell."]) );
  SetListen( ([ "default" : "A light breeze stirs the leaves around you."]) );
  SetObviousExits("south");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

