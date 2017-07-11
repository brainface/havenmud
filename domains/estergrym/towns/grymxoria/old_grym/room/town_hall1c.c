// Title: Destroyed Grymxoria Town
// File: town_hall1c.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Office of the mayor in the Grymxoria Town Hall
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
    SetShort("the Town Hall of Grymxoria");
    SetLong("This is the former office of the Warlord of Grymxoria. "
	    "What were once fine tapestries adorn the otherwise "
        "bare stone walls but they have now been slashed and "
        "torn, many ripped down and thrown to the floor. The "
        "splintered remains of a large wooden desk sit in the "
        "center of the room.");
    SetItems( ([
        "tapestries" : "Fine tapestries depicting the history of "
            "the town of Grymxoria, now slashed and ruined.",
        "desk" : "A large desk made out of good, hard, wood. It "
            "has been smashed in many places, and is now little "
            "more than a splintered hunk of wood."]) );
    SetExits( ([ "down" : G_ROOM + "town_hall2b" ]) );
    }
