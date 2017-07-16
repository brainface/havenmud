/* First in a series of rooms for Nova Roma */
#include <lib.h>
#include "../rome.h"
#define WORLD "/domains/peninsula/virtual/vimp/0,0"
inherit LIB_ROOM;
int WanderFilter();

static void create() {
	::create();
	SetShort("along the Via Imperialis");
	SetExits( ([
	  "south" : ROME_ROOM "vi02",
	  ]) );
  AddExit("north", WORLD, (: WanderFilter :) );
	SetLong("The Via Imperialis continues to the north from here, leading "
	        "out of the city and into the unconquered lands that lay out"
	        "side the control of the Empire. To the south, the city spreads "
	        "off into the distance, the jewel of the Empire. The stones of "
	        "the road are fiercely organized and extremely easy to travel "
	        "on.");
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
     ROME_NPC "centurion" : 1,
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city swell from the south.",
    ]) );
}	           

int WanderFilter() {
  if (this_player()->id("wander")) return 0;
  return 1;
}
