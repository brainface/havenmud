#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Imperialis");
	SetExits( ([
          "north" : ROME_ROOM "vi05",
	  "south" : ROME_ROOM "vi07",
          "east"  : ROME_ROOM "bazaar",
	  ]) );
  SetLong("The Via Imperalis continues to the north and south from "
          "here. Off to the south lie the docks which connect "
          "the Empire via the Inner Sea. To the east lies the Sanctum "
          "Bazaar, home to merchants from both the Empire and the "
          "further reaches. To the north, the road meets up with "
          "the Via Esteros, which connects Sanctum to the rest of the "
          "Empire.");
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
   ROME_NPC "child_citizen" : 1,
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city swell from the south.",
    ]) );
}	           
