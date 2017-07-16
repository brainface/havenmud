#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Imperialis");
	SetExits( ([
          "north" : ROME_ROOM "vi01",
	  "south" : ROME_ROOM "vi03",
          "east" : ROME_ROOM "rd13",
	  ]) );
  SetLong("The Via Imperialis meets up the Via Orcus here, heading "
          "north and south while the Via Orcus heads east. To the "
          "north, the city of Sanctum ends and the less travelled "
          "northlands open up endlessly onward. To the east, the Via "
          "Orcus leads to the Thorian Temple. Thick paving stones "
          "make travel easy along the road, while some small buildings "
          "line the roads as the road gets nearer the town center.");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the north and south.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ({ "building", "buildings" }) : "These small buildings are homes "
        "and other non-public buildings.",
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
