/*  west passage 2 */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(45);
  SetShort("above the Great Hall");
  SetLong("A large spiraling ramp leads back down to the Great "
    "Hall from here. To the east lie the great forges, the center of the "
    "dwarven military effort. Built into the walls of this area is a "
    "tavern. The stone floor seems to be well crafted and designed with "
    "the care that only dwarves can give masonry.");
  SetItems( ([
    ({"hall","great hall", "Great Hall", "great hall of the dwarves",
      "Great Hall of the Dwarves", "ceiling", "structure", "mountain"}) :
      "The Great Hall of the Dwarves is cut from the stone of the "
      "mountain and is immeasurably large, both in width and "
      "height especially.  Its ceiling towers high and supports the "
      "unimaginable weight of the mountain itself.",
    ({"ceiling", "opening"})  :
      "The opening of the passage is tremendous and wide, but "
        "the ceiling is rather low.",
     ({"stone floor", "floor"})  :
       "The floor is made of stone.",
    ({"stone"})  :
      "The stone is very hard.",
    ({ "tavern" }) :
      "The tavern is a well built stone face with pictures of beer steins "
      "carved into the very walls.",
    ]) );
  SetItemAdjectives( ([
    "hall"  :  ({"big", "massive", "enormous", "immense", "huge"}),
    "ceiling"  :  ({"wide", "tremendous", "short", "low"}),
    ]) );
  SetExits( ([
    "east" : AVERATH_ISLAND "-7,-3,1",
    "down" : AVERATH_ISLAND "-8,-3,0",
  ]) );
  SetEnters( ([
    "tavern" : G_ROOM "tavern",
    ]) );
  SetSmell( ([
    "default" : "The faint scent of smelted ores and stale beer lingers in the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of dwarven singing are faint.",
    ]) );
  SetInventory( ([
    G_NPC "pouch_vendor" : 1,
    ]) );
}
