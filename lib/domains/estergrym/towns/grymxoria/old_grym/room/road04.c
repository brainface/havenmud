// Title: Destroyed Grymxoria Town
// File: road04.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Exile Avenue in Grymxoria
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
    SetShort("Exile avenue");
    SetLong("In the rogues quarter of Grymxoria. Exile avenue, "
        "named both after the event in Nosferatu history and "
        "after its denizens, leads off to the east and west. On "
        "either side of the road decaying and destroyed buildings "
        "can be seen, all crumbling and empty. The "
        "cavern wall can be dimly seen to the west.");
    SetExits( ([ "west" : G_ROOM + "road03",
        "east" : G_ROOM + "road05" ]) );
    SetItems( ([
        ({"decaying buildings","buildings","building","rubble"}) :
            "This area of the city always was desheveled, but now "
            "it is just an empty husk. Crumbling buildings line the "
            "streets and rubble is everywhere.",
        ]) );
    }
