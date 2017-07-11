#include <lib.h>
#include <domains.h>
#include "../cata.h"
inherit LIB_ROOM;

static void create() {
::create();
SetClimate("indoors");
SetAmbientLight(30);
SetShort("at the base of the stairwell");
SetLong("A wide expansive room spreads out all around you."
        " In the center, the base of a staircase begins"
        " to ascend to upper levels. The floor is made"
        " of large bricks arranged in a rectangular"
        " pattern which looks to lack creativity. To"
        " the east and west hallways open up.");
  SetItems( ([
        ({ "room", "area" }) : (: GetLong :),
        ({ "bricks", "walls", "brick", "wall", "floor" }) :
            "The walls and floor are made of large stone"
            " bricks that are arranged in a rectangular"
            " pattern.",
        ({ "stairs", "steps", "stair", "step", "staircase" }) : 
            "The stairs are very wide"
            " and have been worn smooth from years and"
            " years of use. They lead up.",
        ({ "hall", "hallways", "hallway", "halls" }) :
            "To the east and west hallways open up"
            " allowing one to go either way.",
                     
    ]) );
  SetItemAdjectives( ([
        "stairwell" : "dark",
        "bricks" : ({ "large", "stone", "rectangular" }),
        "stairs" : ({ "wide", "smooth", "old", "base of" }),
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
      "up" : CATA_ROOM "stair2",
      "east" : CATA_ROOM "stair4", 
      "west" : CATA_ROOM "stair7",
     ]) );
}
