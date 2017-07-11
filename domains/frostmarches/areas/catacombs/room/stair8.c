#include <lib.h>
#include <domains.h>
#include "../cata.h"
inherit LIB_ROOM;

static void create() {
::create();
SetClimate("indoors");
SetAmbientLight(30);
SetShort("the entrance to the catacombs");
SetLong("The hallway is lined with large stone bricks"
        " that are arranged in a rectangular pattern."
        " The floors have also been set into a similar"
        " pattern but the stones have been worn slick"
        " by years of use. A stairwell leads down into"
        " the catacombs while the hallway opens up to"
        " the east.");
  SetItems( ([
        ({ "room", "area", "hall", "hallway" }) : (: GetLong :),
        ({ "bricks", "walls", "brick", "wall", "floor" }) :
            "The walls and floor are made of large stone"
            " bricks that are arranged in a rectangular"
            " pattern.",
        ({ "stairs", "stairwell" }) : 
          "A stairwell made of large rectangular bricks"
          " leads down into the catacombs.",         
    ]) );
  SetItemAdjectives( ([
        "bricks" : ({ "large", "stone", "rectangular" }),
    ]) );
  SetSmell( ([
      "default" : "The burning torches do little to mask the smell"
                " of rot and decay.",
      ]) );
  SetListen( ([
      "default" : "A slight murmer of activity echoes throughout.",
      ]) );
  SetInventory( ([
      ]) );
  SetExits( ([
      "down" : FROSTMARCHES_VIRTUAL "catacombs/0,0",
      "east" : CATA_ROOM "stair7", 
     ]) );
}
