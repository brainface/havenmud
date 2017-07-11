// Title: Destroyed Grymxoria Town
// File: road09.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Exile Avenue Road in Grymxoria
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
    SetLong("In the edge of the ruined rogues quarter of Grymxoria. "
        "Exile avenue comes to an end against the wall of the "
        "cavern here. Exile avenue, named both after the event "
        "in Nosferatu history and after its former denizens, "
        "leads off to the west. Both sides of the road are lined "
        "with decaying buildings and rubble.");
    SetExits( ([ "west" : G_ROOM + "road08"]) );
    SetItems( ([
        ({"decaying buildings","buildings","building","rubbles"}) :
            "This area of the city always was desheveled, but now "
            "it is just an empty husk. Crumbling buildings line the "
            "streets and rubble is everywhere.",
        ]) );
    }
