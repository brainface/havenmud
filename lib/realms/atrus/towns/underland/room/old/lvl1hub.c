/* Atrus@Haven 
   Level 1 Hub 
   Municipal District
   
   Enters : Town Hall
            Public Works
*/

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the municipal square");
  SetExits( ([
    "east" : UNDER_ROOM "cemetery",
    "west" : UNDER_ROOM "level1west",
    "north" : UNDER_ROOM "level1north",
    "south" : UNDER_ROOM "level1south",
    "down" : UNDER_ROOM "level2hub",
    "up" : UNDER_ROOM "level0hub",
        ]) );
  SetSmell("The smells of fresh baked bread comes from the food cart.");
  SetListen("The bustle of politicians is almost drowned out by the sound of steam pipes.");
  SetLong("Here in the center of the municipal square the bronze and brass cogs are "
     "brightly polished with large, well greased bearings that attempt to deaden the "
     "sound of the machinery. A large clock stands to the cardinal north that is built "
     "into the front of the town hall. A small food cart stands to the southwest corner "
     "of the square, it is covered by a near horizontal cog that is easily twice in "
     "diameter what a human male is tall. The floor is polished marble. There are large "
     "steam pipes woven around the clockworks that are mounted on the wall. To the "
     "southeast stands the public works building where the local government-run charity "
     "is headquartered, along with various departments of state. The faces of the "
     "buildings are covered in beaten brass plates."
    );
  SetItems( ([
    ({ "cog", "cogs", "gear", "gears", "clockwork", "clockworks", "bearings", "bearing", 
       "mounts", "mount" }) : "The large gears and cogs that make up the clockworks are "
              "brightly polished. The lubrication of the bearings and contact points of "
              "each integrated part ensure the quietest operation possible while allowing "
              "an efficient transfer of essential power throughout the city. There is a "
              "very large gear mounted horizontally on the southwest wall that appears "
              "as a roof over a small food cart. The bronze mounts bolt through the plates "
              "on the walls to secure the clockworks.",

    ({ "hall", "building" }) : "cityhall.",
    ]) );
  SetEnters( ([
    "hall" : UNDER_ROOM "city_hall",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : random(3),
    UNDER_OBJ "clock" : 1,
    ]) );
}
