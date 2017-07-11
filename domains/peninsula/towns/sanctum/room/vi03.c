#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Imperialis");
	SetExits( ([
          "north" : ROME_ROOM "vi02",
	  "south" : ROME_ROOM "vi04",
          "west"  : ROME_ROOM "rd06",
	  ]) );
  SetLong("The Via Imperialis continues to the north and south from "
          "here. To the west lies the Via Circuses, which leads to "
          "the Sanctum Colosseum and the Eclat Temple. Further to "
          "the south lies the Moneychanger's building. The road is "
          "paved here with smooth pieces of stone, making it a very "
          "easy pathway to walk upon. Small homes line the streets here, "
          "evidence of the large population of the Imperial City.");
	SetItems( ([
    ({ "house", "homes" }) : "The homes are standard wood and stone "
        "buildings with little to distinguish one from the other.",
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the north and south.",
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
    "default" : "The sounds of the city swell from the south.",
    ]) );
}	           
