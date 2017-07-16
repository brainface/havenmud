// Title: Destroyed Grymxoria Town
// File: town_hall2b.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Office of the Grymxoria Town Hall
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
    SetShort("the office of the former Town Hall of Grymxoria");
    SetLong("This used to be a large office in the Grymxoria "
        "town hall. Scribes, messengers, councilors, and "
        "assistants would run to and fro attending to their "
        "respective tasks. Now the room serves for more living "
        "space for the Daemon hoard."
        "At the north end of the room is a small staircase that "
	    "leads up to an office.  ");
    SetItems( ([
        ({ "stair", "stair case" }) : "A stair case of "
            "black stone, leading up."]) );
    SetExits( ([ "east" : G_ROOM + "town_hall3b",
        "west" : G_ROOM + "town_hall1b",
        "up" : G_ROOM + "town_hall1c"]) );
    SetInventory( ([
/*
        G_NPC + "daemon" : 2 + random(3),
*/
        ]) );
    }
