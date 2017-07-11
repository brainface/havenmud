/*  Kobold Lair - Typical Dens  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small kobold den");

  SetLong("A small and dirty room, this is the typical kobold den.  Around "
          "the den are small puddles of water that have seeped in through "
          "the cracks in the ceiling.  Also, several sticks and rags lie "
          "around the room, as if carelessly thrown around.");

  SetSmell( ([
    "default"  :  "The place smells of damp dog and stagnant water.",
  ]) );

  SetListen( ([
    "default"  :  "The yapping of kobolds could drive one crazy.",
  ]) );

  SetExits( ([
    "west"  :  ROOMLV1 + "/kobold1",
  ]) );
  SetObviousExits("west");

  SetItems( ([
    ({ "small kobold den", "small den", "kobold den", "den" })  : 
       (: GetLong :),
    ({ "item", "items", "tattered rags", "rags", "rag", "sticks", "stick",
       "rocks", "rock", "tattered rag", "orange rags", "orange rag", "red rag",
       "red rags" })  :
       "The den is very messy with tattered red and orange rags, sticks, and "
       "rocks making up most of the mess.",
    ({ "ceiling", "cracks", "crack" })  :
       "The many cracks that criss-cross and riddle the ceiling makes it look "
       "very unstable and prone to fall at any time.  This also gives the "
       "ceiling the look of shattered glass.",
    ({ "water", "small puddles", "puddles", "small puddle", "puddle" })  :
       "The water is dripping from one of the many cracks in the ceiling.  "
       "The water has gathered into one of many puddles lying randomly around "
       "the room.",
  ]) );

  SetInventory( ([ NPCS + "/koboldchildm" : 1,
                   NPCS + "/koboldchildf" : 1,
  ]) );
}
