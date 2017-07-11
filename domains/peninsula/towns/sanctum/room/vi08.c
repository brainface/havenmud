#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Imperialis near the Sanctum docks");
	SetExits( ([
          "north" : ROME_ROOM "vi07",
	  "south" : ROME_ROOM "docks",
	  ]) );
  SetLong("The road continues to the north and south from here. "
          "Directly to the south are the Sanctum docks, which "
          "connect the city of Sanctum to the rest of the world "
          "via the Blood Sea. To the north, the road leads back "
          "in to the city proper. Lying on the side of the road, "
          "looking like a cast off bit of scrap wood, is the "
          "Broken Stine Tavern.");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the north and south.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
     ({ "building", "tavern", "stine" }) : "The Broken Stine is "
        "a sad excuse for a tavern.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    "building" : ({ "broken", "stine", }),
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The smell of the sea wafts from the south.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city swell from the north.",
    ]) );
  SetEnters( ([
    "building" : ROME_ROOM "inn",
    ]) );
}	           
