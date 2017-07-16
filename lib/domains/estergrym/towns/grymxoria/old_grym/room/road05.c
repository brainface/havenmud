// Title: Destroyed Grymxoria Town
// File: road05.c
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
    SetLong("In the ruins of the rogues quarter of Grymxoria. "
        "Exile avenue, named both after the event in Nosferatu "
        "history and after its one time denizens, leads off to "
        "the west and meets up with Blood River road to the east. "
        "Both sides of the road are lined with decaying buildings "
        "and heaps of rubble.");
    SetExits( ([ "west" : G_ROOM + "road04",
        "east" : G_ROOM + "road06" ]) );
    SetItems( ([
        ({"decaying buildings","buildings","building","rubble"}) :
            "This area of the city always was desheveled, but now "
            "it is just an empty husk. Crumbling buildings line the "
            "streets and rubble is everywhere.",
        ]) );
    }
