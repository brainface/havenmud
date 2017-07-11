#include <lib.h>
#include <domains.h>
#include "../cata.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("a dark stairwell");
  SetLong("Large stone bricks make up the walls of this"
        " stairwell. The stairs themselves are very wide"
        " and worn smooth by the ages. Every couple steps"
        " sconces have been affixed to the walls to provide"
        " light.");
  SetItems( ([
        "stairwell" : (: GetLong :),
        ({ "bricks", "walls", "brick", "wall" }) :
            "The walls are made of large stone"
            " bricks.",
        ({ "stairs", "steps", "stair", "step" }) : 
            "The stairs are very wide"
            " and have been worn smooth from years and"
            " years of use.",
        ({ "sconce", "sconces", "torch", "torches" }) :
            "Every couple steps sconces have been"
            " affixed to the wall to provide light"
            " for the stairwell.",
    ]) );
  SetItemAdjectives( ([
        "stairwell" : "dark",
        "bricks" : ({ "large", "stone" }),
        "stairs" : ({ "wide", "smooth", "old" }),
    ]) );
  SetSmell( ([
      "default" : "The burning torches do little to mask the smell"
                " of rot and decay.",
      ]) );
  SetListen( ([
      "default" : "A slight murmer of activity rises from below.",
      ]) );
  SetInventory( ([
      CATA_NPC "banshee" : 1,
      ]) );
  SetExits( ([
      "up" : CATA_ROOM "stair1",
      "down" : CATA_ROOM "stair3", 
     ]) );
}
