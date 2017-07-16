#include <lib.h>
#include <domains.h>
#include "vest.h"
inherit LIB_ROOM;

int X, Y;

void Setup();

static void create(int x, int y) {
	string e, w;
	::create();
	SetShort("along the Via Esteros");
	X = x; Y = y;
	e = VIA_ROOM + (X + 1) + "," + Y;
	w = VIA_ROOM + (X - 1) + "," + Y;
	if (X == 0) {
                w = PENINSULA_TOWNS "sanctum/room/rd05";
	}
	if (X != 25) AddExit("east", e);
	AddExit("west", w);
	Setup();
}

void Setup() {
	SetLong("The Via Esteros runs through the heart of the Empire. "
	        "To the east lies the port city of Parva, while to the "
	        "west lies the capital of the Empire, Sanctum. The paved "
	        "road is very well tended here, with trees lining the path "
	        "in a neat and organized manner. Off to the south, the waters "
	        "of the Inner Sea lap against the shore, calling to the "
	        "foolish to sail them.");
	SetSmell( ([
	  "default" : "A faint fishy odor comes from the sea.",
	  ]) );
	SetListen( ([
	  "default" : "Birds, waves, and bugs are all that chitter around.",
	  ]) );
}
	
