#include <lib.h>
#include <domains.h>
#include "../cata.h"
inherit LIB_ROOM;

static void create() {
::create();
SetClimate("indoors");
SetAmbientLight(30);
SetShort("a chapel");
SetLong("The stone walls of this chapel have been"
        " decorated with matching tapestries that"
        " hang low, nearly touching the floor."
        " In the center of the chapel a large"
        " altar has been placed and dressed"
        " in liturgical vestments. The floor is"
        " made of rectangular bricks. A hallway"
        " leads to the west while a small chamber"
        " can be seen to the east.");
  SetItems( ([
        ({ "chapel" }) : (: GetLong :),
        ({ "bricks", "brick", "floor" }) :
            "The floors are made of large"
            " rectangular bricks that have been"
            " worn smooth by years of use.",
        ({ "altar", "dressings", "vestments" }) :
            "The altar is made of a smooth white"
            " stone and has been dressed with"
            " black drapes that are obviously of"
            " a liturgical nature.",
        ({ "tapestries", "tapestry", "wall", "walls" }) :
           "The walls are adorned with large black"
           " tapestries that show signs of aging"
           " with rips and holes in various places.",
         
    ]) );
  SetItemAdjectives( ([
        "bricks" : ({ "large", "stone", "rectangular" }),
        "altar" : ({ "large", "white", "stone", "black", "liturgical" }),
        "tapestries" : ({ "large", "black", "long", "matching", "stone" }),
    ]) );
  SetSmell( ([
      "default" : "The burning torches do little to mask the smell"
                " of rot and decay.",
      ]) );
  SetListen( ([
      "default" : "A slight murmer of activity echoes throughout.",
      ]) );
  SetInventory( ([
      CATA_NPC "plague_bearer" : 2,
      CATA_OBJ "casket" : 1,
      ]) );
  SetExits( ([
      "west" : CATA_ROOM "stair4",
      "east" : CATA_ROOM "stair6", 
     ]) );
}
