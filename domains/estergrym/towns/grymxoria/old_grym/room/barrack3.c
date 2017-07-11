// Title: Destroyed Grymxoria Town
// File: barrack3.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Fighter only room of the destroyed barracks
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("the former Grymxorian Guard and Army room");
    SetClimate("indoors");
    SetDomain("Estergrym");
    SetTown("Grymxoria");
    SetAmbientLight(0);
    SetExits( ([
        "west" : G_ROOM +"barrack1",
        ]) );
    SetLong("This used to be the Grymxorian Guard and Army room until "
        "their defeat at the hands of the Daemon invaders. There is a "
	    "large, empty fireplace, with a few peices of charcoal in it. "
        "There are also several destroyed tables with and a half dozen "
        "smashed chairs scattered about the room.");
    SetItems( ([
        ({ "fire", "fireplace" }) : "A large stone fireplace, cold now, "
            "with a few bits of charcoal in the bottom.",
        ({"tables","table","chair","chairs"}) : "The smashed remains of "
            "round wooden tables and a half dozen destroyed chairs "
            "are scattered around the room.",
        ]) );
    }
