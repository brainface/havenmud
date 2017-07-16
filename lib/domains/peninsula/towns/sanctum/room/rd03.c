#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Esteros");
	SetExits( ([
          "east" : ROME_ROOM "rd04",
          "west" : ROME_ROOM "rd02",
	  ]) );
  SetLong("The Via Esteros continues to the east and west from here. "
          "Off to the east lies both the Soirin Temple and the "
          "Eastern Gate from Sanctum. The Soirin Temple is a black "
          "marble affair with golden trim, giving an appearance of "
          "wealth and prestige to the Temple. The eastern gate leads "
          "out from the City of Sanctum to the rest of the Empire.");
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
