// Title: Destroyed Grymxoria Town
// File: road08.c
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
    SetLong("In the heart of the former rogues quarter of "
        "Grymxoria. Exile avenue, named both after the event "
        "in Nosferatu history and after its former denizens, "
        "leads off to the east and west. Both sides of the "
        "road are lined with decaying buildings and rubble. "
        "The cavern wall can be dimly seen to the east.");
    SetExits( ([ "east" : G_ROOM + "road09",
        "west" : G_ROOM + "road07" ]) );
    SetItems( ([
        ({"decaying buildings","buildings","building","rubbles"}) :
            "This area of the city always was desheveled, but now "
            "it is just an empty husk. Crumbling buildings line the "
            "streets and rubble is everywhere.",
        ]) );
    }
