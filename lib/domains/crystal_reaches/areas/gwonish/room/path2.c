#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("a fork in the road");
  SetLong( "The road splits here with a well traveled path leading north "
           "to a small cabin and the main road continuing to the southwest, "
           "deeper into the thickening forest.");

  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  "
                        "However, grass and small weeds are starting to "
                        "grow over much of the road.",
               ({"trees", "forest"}) : "The trees stretch high into the sky "
                         "all around.  They are not very many around though.  "
                         "In fact, there are many stumps where most of the "
                         "forest has been cleared.",
               "cabin" : "Smoke spirals up from a hole in the cabin's roof "
                         "and dissipates.",
               "path" : "Strangely, the path is in much better care than "
                        "the road, in spite of its dirt composition."]) );

  SetExits( ([ "southwest" : GWONISH + "room/path3",
    "east" : GWONISH + "room/path1",
               "north" : GWONISH + "room/outsidecabin.c",
              ]) );

  SetSmell( ([ "default" : "The open air of the plains mixes with a fresh "
               "cut wood smell."]) );
  SetListen( ([ "default" : "A light breeze stirs the leaves around you."]) );

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(3),
                 GWONISH + "npc/r_animal" : random(4)]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

