// Title: Destroyed Grymxoria Town
// File: road06.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Intersection of Blood River Road and
//			Exile Avenue in Grymxoria
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(0);
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("intersection of Blood River road and Exile avenue");
    SetLong("This is the intersection of Blood River road and Exile avenue. "
        "Blood River road continues to the north towards the "
		"ruins of the gate, and south towards the center of "
		"town. Exile avenue leads off to the east and west "
		"into Grymxoria's former rogues quarter. The Blood "
		"river flows down the center of the two lane Blood "
		"River road from north to south. To the north is "
        "the remains of the Grymxoria city barracks.");
    SetItems( ([
        ({ "river", "blood river", "Blood River" }) : "The Blood River "
            "flows down the center of the divided two lane road. "
            "It gets its name from the reddish color of the water from "
            "the large amounts of iron and copper in it."]) );
    SetListen( ([
            "default" : "The river swishes and gurgles eerily."]) );
    SetExits( ([ "north" : G_ROOM + "road02",
        "south" : G_ROOM + "road10",
        "east" : G_ROOM + "road07",
        "west" : G_ROOM + "road05"]) );
    }
