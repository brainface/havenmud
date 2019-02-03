#include <domains.h>
#include <lib.h>
#include "../path.h"
#define DUUK_TOWER_THING CRYSTAL_REACHES_AREAS + "rath_tower/room/outer"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("the base of a small hill");
  SetLong( "The road ends here at the base of a small hill and continues "
           "on to the east.  A tower of some sort rests at the summit of "
           "the small hill, that appears to overlook the sea to the west.  "
           "Down the slope to the south begins what looks to be an "
           "enormous swamp." );

  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region",
               ({"trees", "forest"}) : "Most of the trees here have been "
                        "removed, leaving not even scars upon the earth or "
                        "stumps to remember them by.  Natural growth begins "
                        "again to the east and south.",
               "cliff" : "The cliff is but a part of long palisades.",
               "palisades" : "The palisades stretch far to the southeast "
                             "growing taller the further south they are.  "
                             "They curve around to create a boundary to "
                             "the north as well.",
               "swamp" : "A huge dark swamp begins a short distance to the "
                         "south.",
               "hill" : "The hill is really just a slight swell in the slope "
                        "that the palisades have become as they slope towards "
                        "the sea.",
               "tower" : "This is the first major piece of stonework to "
                            "be found anywhere in the area.  It must be a "
                            "structure of some importance.",
               "sea" : "An enormous amount of fog rolls over the sea, "
                       "restricting your view to a few hundred yards.  "
                       "Perhaps the fog is a result of the strange warmth "
                       "here."]) );

  SetExits( ([ "east" : GWONISH + "room/path9",
    ]) );
  SetEnters( ([
    "tower" : CRYSTAL_REACHES_AREAS "rath_tower/room/entrance",
    ]) );

  SetSmell( ([ "default" : "The stagnant rotting smell of a swamp assaults "
                           "you."]) );
  SetListen( ([ "default" : "The air is full of the sounds of birds, "
                            "insects and frogs."]) );

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(4),
                 GWONISH + "npc/r_animal" : random(6)]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

