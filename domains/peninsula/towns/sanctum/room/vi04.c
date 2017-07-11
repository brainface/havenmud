#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Imperialis");
	SetExits( ([
          "north" : ROME_ROOM "vi03",
	  "south" : ROME_ROOM "vi05",
	  ]) );
  SetLong("The Via Imperialis continues to the north and south "
          "from here. Directly to the east is the office of the "
          "local Moneychanger.  It serves as both currency exchange "
          "and bank for the city of Sanctum. The stone paved road "
          "makes travel very easy in this part of town. "
          "Directly to the south is the intersection of the Via "
          "Imperialis and the Via Esteros, one of the main roadways "
          "inside the Empire.");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the north and south.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ({ "building", "bank", "office", "moneychanger" }) : "The bank is a large stone "
         "structure with marble columns.  It does not appear to have "
         "an entrance from this road, only from the Via Esteros.",
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
    "default" : "The sounds of the city swell from the south.",
    ]) );
}	           
