#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Esteros");
  SetLong("The Via Esteros continues to the east and west from here. "
          "Farther to the east lies the eastern gate which leads "
          "from Sanctum to the rest of the Empire. Lying along "
          "the north side of the road is the Soirin Temple. "
          "Its black marble facade is lined in gold, giving "
          "the impression of a very wealthy temple. Further "
          "west the road branches off to connect with most of "
          "city.");
	SetExits( ([
          "east" : ROME_ROOM "rd05",
          "west" : ROME_ROOM "rd03",
	  ]) );
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ({ "temple" }) : "The Soirin Temple is a black marble building "
            "with golden trim.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    "temple" : ({ "soirin", "black", "marble", }),
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city are alive and vibrant.",
    ]) );
  SetEnters( ([
    "temple" : ROME_ROOM "soirin_temple",
    ]) );
}	           
