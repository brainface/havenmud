#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Circuses");
	SetExits( ([
          "east" : ROME_ROOM "rd06",
          "west" : ROME_ROOM "rd08",
	  ]) );
  SetLong("The Via Circuses continues on to the east and west from here. "
          "Off to the east, the road meets the Via Imperialis in a 'T' "
          "intersection. Off to the west lie both the beautiful Eclat "
          "Temple and the massive Sanctum Colosseum.");
	SetItems( ([
    "temple" : "The Eclat Temple is a white marble building of stunning "
               "beauty.",
    "colosseum" : "The Colosseum is a massive structure of stone that towers "
                  "over all other structures in town.",
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
