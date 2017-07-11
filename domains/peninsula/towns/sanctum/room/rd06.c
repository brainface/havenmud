#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Circuses");
	SetExits( ([
          "east" : ROME_ROOM "vi03",
          "west" : ROME_ROOM "rd07",
	  ]) );
  SetLong("The Via Circuses continues to the west from here. To the "
          "east, the road meets with the Via Imperialis to form a \"T\" "
          "intersection. Further along the Via Circuses are the "
          "Sanctum Colosseum and the Eclat Temple. The road, like "
          "all other roads in Sanctum, is evenly paved with small "
          "smooth stones.");
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
