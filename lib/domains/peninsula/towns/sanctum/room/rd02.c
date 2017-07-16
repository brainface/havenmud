#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Esteros");
  SetLong("The Via Esteros contines to the east and west. South of here "
          "is a quiet contemplation glade. It serves as the local "
          "cemetery. Further to the west, the road meets the Via Imperialis "
          "to form the center of the Imperial City. Off to the east is "
          "the Soirin Temple. At the extreme end of the road lies the "
          "eastern gate exiting the town.");
	SetExits( ([
          "east" : ROME_ROOM "rd03",
          "west" : ROME_ROOM "rd01",
	  ]) );
	SetItems( ([
    ({ "glade", "cemetery" }) : "The peaceful glade to the south "
         "serves as the local cemetery.",
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ]) );
    SetEnters( ([
        "glade" : ROME_ROOM "cemetery",
  ]) );
  SetItemAdjectives( ([
    "glade" : ({ "peaceful", "quiet", "contemplation" }),
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
