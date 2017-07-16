// Title: Destroyed Grymxoria Town
// File: town_hall3b.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Meeting room in the Grymxoria Town Hall
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

 
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(20);
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("the former Town Hall of Grymxoria");
    SetLong("This used to be a public meeting room in the eastern "
        "wing of the Grymxoria town hall. It is a large open "
        "room with a large fire place at one end, and several "
        "large tables with chairs scattered around. At the back "
        "of the room is a large bulletin board for general town "
        "posting. Here too the Daemons have taken up residence "
        "and their occupation is obvious from the piles of refuse "
        "and scattered bones.");
    SetItems( ([
        "fire place" : "A large stone fire place with a good size fire "
            "in it.",
        "tables" : "Large rectangular wooden tables scattered about the "
            "room",
        "chairs" : "Wooden chairs scattered about the room and around "
            "tables.",
        ({"refuse","piles","piles of refuse"}) : "About the "
            "room are scatted piles of refuse ... Food bits "
            "and other scraps.",
        ({"scattered bones","bones"}) : "Bones are scattered about "
            "the room, no doubt left from meals.",
        ]) );
    SetExits( ([ "north" : G_ROOM + "church3b",
        "west" : G_ROOM + "town_hall2b",
        "down" : G_ROOM + "town_hall2a" ]) );
    SetInventory( ([
/*
        G_NPC + "daemon" : 1 + random(2),
*/
	    ])  );
    }
