/*  Kobold Lair - Typical Dens  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small kobold den");

  SetLong("This seems to be the typical kobold den.  It is very small and "
          "messy.  Items of no worth are scattered around the room:  tattered "
          "rags, sticks, and rocks to name a few.  The ceiling looks as "
          "though it is about to collapse with water dripping from cracks "
          "that give the ceiling a look similar to a piece of shattered "
          "glass.");

  SetSmell( ([
    "default"  :  "The place smells of damp dog and stagnant water.",
  ]) );

  SetListen( ([
    "default"  :  "The yapping of kobolds could drive one crazy.",
  ]) );

  SetExits( ([
    "north"  :  ROOMLV1 + "/kobold1",
  ]) );
  SetObviousExits("north");

  SetItems( ([
    ({ "small kobold den", "small den", "kobold den", "den" })  : 
       (: GetLong :),
    ({ "item", "items", "tattered rags", "rags", "rag", "sticks", "stick",
       "rocks", "rock", "tattered rag", "mess" })  :
       "The den is very messy with tattered red and orange rags, sticks, and "
       "rocks making up most of the mess.",
    ({ "orange rags", "orange rag", "red rags", "red rag" })  :
       "The orange and red rags are old clothes that have gotten too tattered "
       "to wear anymore.",
    ({ "ceiling", "cracks", "crack" })  :
       "The many cracks that criss-cross and riddle the ceiling makes it look "
       "very unstable and prone to fall at any time.  This also gives the "
       "ceiling the look of shattered glass.",
    ({ "water" })  :
       "The water is dripping from one of the many cracks in the ceiling.",
  ]) );

  SetInventory( ([ NPCS + "/koboldf" : 1,
                   NPCS + "/koboldm" : 1,
                   NPCS + "/koboldchildm" : 1,
                   NPCS + "/koboldchildf" : 1,
  ]) );
}
