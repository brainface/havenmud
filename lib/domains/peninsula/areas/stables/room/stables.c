// mahkefel @ haven
// a stables for sanctum
#include <lib.h>
#include <domains.h>
#include "../vesta.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("an open-air stables");
  SetLong(
    "A well-traveled clearing here holds an open-air stables. Traders, farmers, "
    "wagons and livestock constantly move and mill about. A paved path leads "
    "back to the Via Imperalis."
  );
  SetItems( ([
    ({"stables"}) : "The stables proper is an open timber structure, "
      "with sturdy oak beams holding up a roof lined with terracotta "
      "shingles. Simple wooden walls divide the stalls inside, which hold "
      "a menagerie of horses, mules, and a few stranger creatures.",
    ({"path"}) : "Well-trod cobblestones lead in a straight path back to "
      "the Via Imperalis.",   
    ({"traders","farmers","livestock"}) : "A variety of merchants, human "
      "and not, bicker and banter forth as they deal.",
    ({"wagons", "carts"}) : "Wagons and carts carrying goods and passengers "
      "stop and depart to fill Sanctum's demand for wealth. A few sit idly "
      "to the side, clearly empty and possibly for sale.",
    ({"imperalis","Imperalis","road"}) : "The pride of Sanctum engineers, "
      "the Via Imperalis points like an arrow north to the Havenroad and "
      "south to Sanctum.",
    ({"clearing", "ground"}) : "A wide circle of bare earth, packed hard "
      "by constant passage of countless feed and hooves.",
  ]) );
  SetItemAdjectives( ([
    "clearing"  : ({"well traveled","well-traveled"}),
    "stables"   : ({"open-air", "open air"}),
    "path"      : ({"paved"}),
    "imperalis" : ({"Via", "via"}),
  ]) );
  SetInventory( ([
    VESTA_NPC + "vesta" : 1,
    VESTA_NPC + "galo"  : 1,
    VESTA_NPC + "caius" : 1,
  ]) );
  SetEnters( ([
  ]) );
  SetSmell( ([
     "default" : "It stinks slightly of livestock and overripe fruit. ",
  ]) );
  SetListen( ([
     "default" : "The braying and bahhing of donkeys, goats, and the occasional wyvern fills the air. ",
  ]) );
  SetExits( ([
    "west"  : PENINSULA_VIRTUAL "vimp/0,0",
  ]) );
}

