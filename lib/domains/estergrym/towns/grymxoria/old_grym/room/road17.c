// Title: Destroyed Grymxoria Town
// File: road17.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Abyss Lane in Grymxoria
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
	room::create();
	SetClimate("indoors");
	SetAmbientLight(0);
	SetTown("Grymxoria");
    SetDomain("Estergrym");
	SetShort("Abyss lane");
	SetLong("Abyss lane continues to the east and west. "
		"To the north is the entrance to the eastern wing of the "
		"cathedral of Saa'HaGoth.  And to the south is the entrance "
		"to the eastern wing of the Grymxoria town hall. A large "
		"skywalk extends between the cathedral and the town hall. "
		"Between the two buildings the central courtyard of the "
		"Church - Town Hall complex can be seen. There, the abyss "
		"yawns open like a huge black mouth.");
	SetItems( ([
		({ "hall", "town hall" }) : "A large stone block building "
			"similar in architecture to the church, but not quite as "
			"large.",
		({ "cathedral", "church" }) : "The cathedral looms up "
			"above. Its tallest spire has fallen as though a "
			"great earthquake shook the very foundation of the "
			"city. Colored patches of light can be seen "
			"shining eerily through the stained glass windows of "
			"the cathedral. Large stone gargoyles sit on ledges "
			"looking down on the road.",
		"gargoyles" : "Large black stone gargoyles, their faces "
			"carved in grotesque and frightening expressions, watch "
			"over the cathedral. In the darkness it looks almost as "
			"if their eyes move to watch people passing beneath the "
			"arch."]) );
	SetExits( ([ "east" : G_ROOM + "road18",
		"west" : G_ROOM + "road16"]) );
	SetEnters( ([ "church" : G_ROOM + "church2a",
		"town hall" : G_ROOM + "town_hall2a"]) );
	}
