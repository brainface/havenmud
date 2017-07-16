#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Circuses");
  SetLong("The Via Circuses continues on to the east and west. "
          "Lying to the north is a small building of white marble, "
          "its windows lined in delicate golden trim. This building "
          "serves as the Temple of the Eclat religion. South of here "
          "lies the Sanctum Colosseum, the entrance of which lies to "
          "the east.");
	SetExits( ([
          "east" : ROME_ROOM "rd08",
          "west" : ROME_ROOM "rd10",
	  ]) );
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ({ "temple", "building" }) : "The Eclat Temple is a white building "
          "of marble with golden outlines.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    "temple" : ({ "white", "marble", "small" }),
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
    "temple" : ROME_ROOM "eclat_temple",
    ]) );
}	           
