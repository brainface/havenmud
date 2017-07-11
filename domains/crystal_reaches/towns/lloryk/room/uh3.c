#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("along a road through the Shire");
  SetLong("The roads continues on to the north and south from here. "
          "The rolling hills of the Shire spread out to the west, "
          "and the Crystal Reaches tower over the horizon to the "
          "east. On one side of the road is the Shire commissary, "
            "where citizens of the Shire come to share their goods "
              "and be shared with, should they have need. On the "
             "other side of the road stands a modest tavern."
          );
  SetItems( ([ 
     ({ "commissary", "store", "building" }) :
        "The Shire commissary is a place to share goods and receive "
        "when the need arises.",
     ({ "reaches", "mountains" }) : 
        "The Crystal Reaches are a mountain range that towers over "
        "the horizon to the east.",
     "tavern" : "This appears to be the only tavern in Lloryk, and a "
       "most hospitable place indeed.",
     ({ "hill", "hills" }) : 
        "The rolling hills of the Shire make for excellent farmland.",
     ]) );
  SetItemAdjectives( ([
    "store"   : ({ "shire", }),
    "reaches" : ({ "crystal", }),
    "hill"    : ({ "rolling", }),
    ]) );
  SetInventory( ([ 
    ]) );
  SetExits( ([
     "north" : LLORYK + "room/uh2",
     "south" : LLORYK + "room/uh4",
     ]) );
  SetEnters( ([
     "store" : LLORYK + "room/gen_store",
     "tavern" : LLORYK + "room/tavern",
     ]) );
  SetListen( ([
    "default" : "The sounds of village life echo around the town.",
    ]) );
  SetSmell( ([
    "default" : "The smells of farm life waft in from the west.",
    ]) );
}
