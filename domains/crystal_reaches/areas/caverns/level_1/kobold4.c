/*  Kobold Lair - Typical Dens  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small kobold den");

  SetLong("This typical kobold den looks as if it is about to collapse, with "
          "all the cracks in the ceiling it is surprising that it hasn't "
          "already.  Water leaks in through the cracks and forms puddles on "
          "the floor.  Old tattered rags and sticks are carelessly tossed "
          "around the room.");

  SetSmell( ([
    "default"  :  "The place smells of damp dog and stagnant water.",
  ]) );

  SetListen( ([
    "default"  :  "The yapping of kobolds could drive one crazy.",
  ]) );

  SetExits( ([
    "northwest"  :  ROOMLV1 + "/kobold1",
  ]) );
  SetObviousExits("northwest");

  SetItems( ([
    ({ "small kobold den", "small den", "kobold den", "den" })  : 
       (: GetLong :),
    ({ "item", "items", "tattered rags", "rags", "rag", "sticks", "stick",
       "rocks", "tattered rag", "old tattered rags", "old tattered rag",
       "rock", "old rags", "old rag" })  :
       "The den is very messy with tattered red and orange rags, sticks, and "
       "rocks making up most of the mess.",
    ({ "ceiling", "cracks", "crack" })  :
       "The many cracks that criss-cross and riddle the ceiling makes it look "
       "very unstable and prone to fall at any time.  This also gives the "
       "ceiling the look of shattered glass.",
    ({ "water", "puddles", "puddle" })  :
       "Water is dripping from several of the many cracks in the ceiling and"
       "has gathered into many puddles on the floor.",
  ]) );

  SetInventory( ([ NPCS + "/koboldf" : 1,
                   NPCS + "/koboldm" : 1,
  ]) );
}
