#include <lib.h>
#include <domains.h>
#include "../grymxoria.h"
#define ROAD "/domains/estergrym/areas/prisoncamp/room/"

inherit LIB_ROOM;

static void create() {
  room::create();
	SetShort("near the main gate to Grymxoria");
	SetLong(
	  "This small cobblestone road is right by "
		"the main gate of Grymxoria. The main gate "
		"of Grymxoria can be seen to the south. There "
		"are many people passing in and out of the gate "
		"in an effort to get work done. To the west is a "
    "road leading back through the mountains."
    );
	SetItems( ([ 
	  ({"road", "cobblestone road" }) : "This small road "
		  "is made out of nicely laid cobblestones.",
		  "grymxoria" : "To the south, Grymxoria can be seen.",
		  "tunnel" : "This small tunnel twists through the "
			"mountain.",
		({"gate", "main gate" }) : "There is a very large gate "
			"to the south that enters "
			"into Grymxoria.",
		  "civilization" : "Grymxoria is the main civilization "
			"in this area and it is located "
			"to the south.",
		  "people" : "People are passing in and out of the "
			"gate to work and to get to different "
			"places in Kailie." ]) );
	SetListen( ([ 
	  "default" : "The sounds of civilization can be heard to the south",
	   ]) );
	SetExits( ([ 
	  "west"  : ESTERGRYM_VIRTUAL "grymxoria_road/40,0",
		"south" : G_ROOM + "road01",
		"north" : ROAD + "gate",
    "down" : ESTERGRYM_TOWNS "vacazar/room/tunnel/t1",
	  ]) );
}
