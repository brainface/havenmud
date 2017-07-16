// The loft of the farmhouse.
// gehnna@havenmud 05/31/01

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create(){
  room::create();

  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("a hay-filled loft");
  SetLong("This loft is apparently used as a sleeping area. "
     "A worn quilt and a few pillows are stacked neatly in a corner. "
     "A wooden crate sits just beside the quilt. Mounds of hay fill "
     "the rest  of the space in the loft. The ceiling is quite low, "
     "and a hole in the floor leads back down to the main room of "
     "the house.");
  SetListen( ([
     "default" : "It is quiet here except for the rustling of hay.",
  ]) );
  SetSmell( ([
     "default" : "A musty smell fills the air.",
  ]) );
  SetItems( ([
     ({"loft","sleeping area","space"}) : (: GetLong :),
     ({"quilt"}) : "This patchwork quilt has intricate designs and hand "
     "embroidery but it is frayed at the edges and faded.",
     ({"pillow","pillows"}) : "These are handmade feather pillows with "
     "little animals embroidered on the linen cases.",
     ({"corner"}) : "A pile of pillows and a quilt are stacked here.",
     ({"crate"}) : "The crate contains several pairs of overalls and a "
     "few faded shirts.",
     ({"hay"}) : "The fresh piles of hay fill the loft.",
     ({"ceiling"}) : "It is only about half the height of a normal ceiling "
     "and the wooden rafters are slanted at an angle to the walls.",
     ({"hole","hole in the floor"}) : "A ladder rests against the hole in the "
     "floor leading down to the rest of the house.",
  ]) );
  SetItemAdjectives( ([
     "quilt" : ({"worn"}),
     "pillow" : ({"few"}),
     "crate" : ({"wooden"}),
     "hay" : ({"mounds of"}),
  ]) );
  SetExits( ([
     "down" : AVERATH_CITY "farmhouse",
  ]) );
}
