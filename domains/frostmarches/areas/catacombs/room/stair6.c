#include <lib.h>
#include <domains.h>
#include "../cata.h"
inherit LIB_ROOM;

static void create() {
::create();
SetClimate("indoors");
SetAmbientLight(30);
SetShort("the vicarage");
SetLong("This small room has a few stone slabs that appear"
        " to have once been sleeping pallets. The walls and"
        " floor are made of large rectangular bricks and"
        " are completely unadorned.");
  SetItems( ([
        ({ "chapel" }) : (: GetLong :),
        ({ "bricks", "brick", "floor", "wall", "walls" }) :
            "The walls and floor are made of the same"
            " large rectangular bricks found throughout"
            " this area. The bricks on the floor have been"
            " worn smooth by years of use.",
        ({ "slabs", "bed", "beds", "pallet", "pallets" }) :
            "About six pallets are arranged in the room."
            " They are little more than stone slabs"
            " that have a flat top.",
       
    ]) );
  SetItemAdjectives( ([
        "bricks" : ({ "large", "stone", "rectangular" }),
        "slabs" : ({ "stone", "large", "sleeping" }),
    ]) );
  SetSmell( ([
      "default" : "The burning torches do little to mask the smell"
                " of rot and decay.",
      ]) );
  SetListen( ([
      "default" : "A slight murmer of activity echoes throughout.",
      ]) );
  SetInventory( ([
      CATA_NPC "vicar" : 1,
      CATA_NPC "plague_bearer" : 2,
      ]) );
  SetExits( ([
      "west" : CATA_ROOM "stair5",
     ]) );
}
