// Title: Destroyed Grymxoria Town
// File: barrack2.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Main room of the destroyed arena
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
int PreExit(string);
inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("the Grymxoria arena");
    SetLong("Inside what was once the Grymxoria arena. The ceiling "
        "slopes up towards the outer wall, supporting the ruined "
        "bleachers of the arena. To the east is a door leading in "
        "to another room.  While to the west is a training room for "
        "use by the gladiators. To the south is a huge set of rusting "
        "iron doors which seem to have been sealed shut and jammed so "
        "they can never open again. There is rubble all around and "
        "everything is covered in dust.");
    SetExits( ([
        "west" : G_ROOM + "arena1",
        "out" : G_ROOM + "road12" ]) );
    AddExit("east", G_ROOM + "arena3");
    SetClimate("indoors");
    SetAmbientLight(0);
    SetItems( ([
        ({"arena"}) : (:GetLong:),
        ({"ceiling","wall","bleachers"}) : "The ceiling slopes up "
            "towards the outer wall, supporting the ruined bleachers "
            "on collapsing beams overhead. Here and there the floor "
            "above has fallen through, but only inky blackness can "
            "be seen through the holes above.",
        ({"east door","door"}) : "A door leading into another room.",
        ({"huge doors","iron doors","doors"}) : "This massive set of "
            "rusting iron doors appears to have been sealed shut by "
            "some magic, and rubble has been piled against it, making "
            "it nearly impossible to ever open again.",
        "dust" : "There is dust covering everything.",
    ]) );
    }
