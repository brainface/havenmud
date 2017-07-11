#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
  SetShort("along the Via Orcus");
	SetExits( ([
          "east" : ROME_ROOM "rd14",
          "west" : ROME_ROOM "vi02",
	  ]) );
  SetLong("The Via Orcus continues to the east and west here. "
          "Directly to the west, the road meets up with the "
          "Via Imperialis to travel to the heart of the city. "
          "To the east, the road comes to an end in front of the "
          "Thorian Temple. The paved stone road is well tended "
          "and easy to travel here, even in a section of town "
          "that is not as well travelled as other parts. ");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
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
    "default" : "The sounds of the city are alive and vibrant.",
    ]) );
}	           
