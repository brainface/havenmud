// Title: Destroyed Grymxoria Town
// File: barrack2.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Sparring room of the destroyed barracks
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a sparring room");
    SetClimate("indoors");
    SetDomain("Estergrym");
    SetTown("Grymxoria");
    SetAmbientLight(0);
    SetExits( ([
        "south" : G_ROOM +"barrack1",
        ]) );
    SetLong("This used to be the sparring room for the Grymxoria "
        "city barracks until the Daemon invasion. Corpses having "
        "no need of weapon training. In the center of the room "
        "there is a circle of bare floor for sparring. There "
        "are many small stains on the floor that look like they "
        "might be blood along with a huge splash across the center of "
        "the circle that looks to have been a great deal of blood ... "
        "Nosferatu blood. Along the walls are smashed racks to hold "
        "weapons, while the weapons are scattered across the room, "
        "most broken and mangled.");
    SetItems( ([
        ({ "room","sparring room","barracks"}) : (:GetLong:),
        ({ "floor", "circle", "blood" }) : "A sparring circle of bare stone "
            "in the center of the room. There are brownish red splotches on "
            "it that look like they might be blood, but those don't compare "
            "to the huge sprawling stain that looks to have been a great deal "
            "of blood ... Nosferatu at that.",
        ({ "rack", "weapon rack","racks", "weapon racks" }) :
            "Smashed racks that used to hold weapons to use for sparring.",
        ({"weapon","weapons"}) : "Smashed, broken, and rusting weapons of all "
            "types lay strewn about the room.",
        ]) );
    }
