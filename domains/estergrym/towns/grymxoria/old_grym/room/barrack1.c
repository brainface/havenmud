// Title: Destroyed Grymxoria Town
// File: barrack1.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Main room of the destroyed barracks
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
int PreExit(string);
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetDomain("Estergrym");
    SetTown("Grymxoria");
    SetShort("the city barracks");
    SetLong("The Grymxoria city barracks is a large stone building "
        "build like a fortress, though apparently that wasn't strong "
        "enough. Guards used to range out from here, protecting "
        "the city from crime, until their demise at the hands of the "
        "vengeful Daemon hoarde. To the north is what was once a "
        "sparring room, and to the east is a doorway with the smashed "
        "and mangled remains of a large set of metal doors hanging in "
        "it.");
    SetExits( ([
        "north" : G_ROOM + "barrack2",
        "out" : G_ROOM + "road02" ]) );
    AddExit("east", G_ROOM + "barrack3");
    SetItems( ([
        ({"barracks","building"}) : (:GetLong:),
        ({"doorway","door","doors","door remains","remains"}) :
            "The twisted and mangled remains of what was once a large "
            "set of heavy metal doors hangs in the doorway.",
        ]) );
    SetClimate("indoors");
    SetAmbientLight(0);
    }
