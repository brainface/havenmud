// Title: Destroyed Grymxoria Town
// File: road07.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Blood River Road in Grymxoria
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
    SetLong("In the heart of the ruins of the rogues quarter of "
        "Grymxoria. Exile avenue, named both after the event "
        "in Nosferatu history and after its former denizens, "
        "leads off to the east and meets up with Blood River "
        "road to the west.");
    SetExits( ([ "east" : G_ROOM + "road08",
        "west" : G_ROOM + "road06" ]) );
    SetItems( ([
        ({"decaying buildings","buildings","building","rubbles"}) :
            "This area of the city always was desheveled, but now "
            "it is just an empty husk. Crumbling buildings line the "
            "streets and rubble is everywhere.",
        ]) );
    }
