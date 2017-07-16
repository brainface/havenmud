#include <lib.h>
#include <domains.h>
#include "../cata.h"
inherit LIB_ROOM;

static void create() {
::create();
SetClimate("indoors");
SetAmbientLight(30);
SetShort("in the western hallway");
SetLong("The hallway is lined with large stone bricks"
        " that are arranged in a rectangular pattern."
        " The floors have also been set into a similar"
        " pattern but the stones have been worn slick"
        " by years of use. The hallway continues to the east"
        " and west.");
  SetItems( ([
        ({ "room", "area", "hall", "hallway" }) : (: GetLong :),
        ({ "bricks", "walls", "brick", "wall", "floor" }) :
            "The walls and floor are made of large stone"
            " bricks that are arranged in a rectangular"
            " pattern.",
         
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
      CATA_NPC "golem" : 1,
      ]) );
  SetExits( ([
      "west" : CATA_ROOM "stair8",
      "east" : CATA_ROOM "stair3", 
     ]) );
}
