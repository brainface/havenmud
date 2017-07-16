/*  Fountain room and cross roads.  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("at the fountain and crossroads");
  SetClimate("temperate");
  
  SetExits( ([
    "west"    : ROOM "/ruins7",
    "north"   : ROOM "/park",
    "south"   : ROOM "/ruins4",
  ]) );

  SetDayLong("The ruins of the city crumble around the town square.  "
             "This square is paved with blue and white tiles; the tiles make "
             "it seem like the ground is flowing in waves.  A well tended "
             "park can be seen to the north.  A road intersects the square "
             "here.  The west end goes deeper into the ruins, while the east "
             "end is covered in rubble from the surrounding buildings.");

  SetNightLong("The ruins of the city seem to loom over the town square "
               "making the square seem isolated.  The square is paved with "
               "blue and white tiles, the light from the fountain causes the "
               "ground to appear like waves on the sea.  The road to the "
               "east is blocked by debris, while a dimly lit park can be seen "
               "to the north.");

  SetItems( ([
    ({ "town square", "square" })   :
       "The ruins of the city tower above the square making it seem small "
       "and isolated.  Small blue and white tiles cover the ground.",
    ({ "ruins of the city", "ruins", "city" })  :
       "Crumbling buildings make up the ruins of this city.  The decaying "
       "buildings loom above the square like stone guardians.",
    ({ "crumbling buildings, crumbling building", "decaying buildings",
       "decaying building",  "stone guardians", "stone guardian",
       "surrounding buildings", "buildings", "building" })  :
       "The buildings surrounding the town square show the ravenges of time.  "
       "Buildings cave-in upon themselves and slowly decay to piles of "
       "rubble.  The decaying buildings look like stone guardians watching "
       "over the remains of the city.",
    ({ "piles of rubble", "pile of rubble", "rubble", "pile", "piles" })  :
       "Piles of rubble are all that remain of some buildings.",
    ({ "small blue and white tiles", "small blue tiles", "small white tiles",
       "blue and white tile", "small blue and white tile", "small blue tile",
       "small white tile", "blue tile", "white tile", "tile", "tiles" })   :
       "The tiles that cover the town square are many different shades of "
       "blue or white.  The tiles are in odd shapes, and form a mosaic which "
       "radiates from the center of the square.",
    ({ "whirlpool", "funnel of water", "mosaic" })  :
       "The mosaic that makes up the floor of the square appears to form a "
       "large funnel of water or whirlpool.  The mosaic almost seems to "
       "undulate like water on the ocean.",
    ({ "dimly lit park", "lit park", "dim park", "park", "well tended park",
       "tended park" })   :
       "There seems to be a well tended park to the north.  The dimly lit "
       "park seems to radiate a calm peaceful aura.",
  ]) );

  SetSmell( ([
    "default"   : "The air smells of strawberries.",
    "fountain"  : "The water of the fountain carries the scent of strawberries.",
  ]) );

  SetListen( ([
    "default"  : "The twinkling of bells surrounds this area.",
    "fountain" : "Each drop sounds like a silver bell as it falls into the basin.",
  ]) );

  SetInventory( ([
     OBJ "/fountain" : 1,
     NPC "/equipper" : 1,
  ]) );
}
