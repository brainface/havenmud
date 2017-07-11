// Title: Destroyed Grymxoria Town
// File: road03.c
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
    SetLong("Near the edge of what was once the rogues quarter "
        "of Grymxoria, but is now little more than a row of "
        "decaying buildings and piles of rubble. Exile avenue "
        "comes to an end against the wall of the cavern here. "
        "The road, named both after the event in Nosferatu "
        "history and after its denizens, leads off to the east.");
    SetExits( ([ "east" : G_ROOM + "road04"]) );
    SetItems( ([
        ({"decaying buildings","buildings","building","rubble"}) :
            "This area of the city always was desheveled, but now "
            "it is just an empty husk. Crumbling buildings line the "
            "streets and rubble is everywhere.",
        ]) );
    }
