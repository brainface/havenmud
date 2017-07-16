#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Imperialis");
	SetExits( ([
          "north" : ROME_ROOM "vi04",
	  "south" : ROME_ROOM "vi06",
          "east" : ROME_ROOM "rd01",
          "west" : ROME_ROOM "forum",
	  ]) );
  SetLong("The Via Imperialis meets the Via Esteros here to form "
          "a 'T' intersection. To the east, the Via Esteros leads "
          "out of the city and into the rest of the Empire. To "
          "the south, the Via Imperialis leads off to the town "
          "docks. Further to the south lies the Sanctum Bazaar, "
          "serving as the center of trade for the majority of "
          "the city. To the west lies the Imperial Forum, the "
          "place where all citizens can discuss the state of the "
          "Empire with its rulers.");
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
    ROME_OBJ "fountain" : 1,
     ROME_NPC "citizen" : 1,
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city swell from the south.",
    ]) );
}	           
