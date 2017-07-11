#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Orcus in front of the Thorian Temple");
	SetExits( ([
          "west" : ROME_ROOM "rd13",
	  ]) );
  SetLong("The Via Orcus ends here in front of the Thorian Temple. Its "
          "large white columns support the stoneworked roof and high "
          "vaulted archways. Fifteen large stone steps lead up in to "
          "the temple, yet traffic in and out of the Temple seems to be "
          "very light at all hours. To the west, the road continues "
          "back into the heart of the town.");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ({ "temple", }) : "The Thorian Temple is a large stone building with "
           "high archways and columns. There are fifteen steps leading "
           "up and in to the temple.",
    ({ "column", "columns" }) : "The columns supporting the ceiling are "
           "large stonework affairs made of whitewashed concrete.",
    ({ "step", "steps" }) : "The Fifteen Steps of the Thorian Temple "
           "are made of massive single-slabs of stone.",
    ({ "archway", "arch", "arches", "archways" }) : "The archways are "
           "normal stone architecture.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    "archway" : ({ "vaulted", "high" }),
    "column" : ({ "large", "white", }),
    ]) );
  SetEnters( ([
    "temple" : ROME_ROOM "thorian_temple",
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
