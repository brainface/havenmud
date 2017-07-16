#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Imperialis");
	SetExits( ([
          "north" : ROME_ROOM "vi06",
	  "south" : ROME_ROOM "vi08",
          "east" : ROME_ROOM "rd12",
	  ]) );
  SetLong("The road continues to the north and south from here. "
          "To the east, a small road leads to the Kylin Temple. "
          "Further south, the road leads to the Sanctum docks, "
          "which connect the city to the rest of the Empire by "
          "sea. "
          );
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the north and south.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city swell from the south.",
    ]) );
}	           
