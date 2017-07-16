// Title: Destroyed Grymxoria Town
// File: road21.c
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
    SetClimate("indoors");
    SetAmbientLight(0);
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("Blood River road");
    SetLong("Blood River road continues to the north. "
        "To the north and partially to each side looms the "
        "Grymxoria town hall. The large gothic style building "
        "straddles the road with a large archway leading into "
        "the central courtyard of the church and town hall "
        "complex. To the south as massive cave in of the cavern "
        "roof above seems to have completely blocked off and "
        "destroyed the rest of the city.");
    SetItems( ([
        "town hall" : "A large gothic style building made of large "
            "blocks of crudely carved black stone.",
        ({"cavern roof","cavern","roof"}) : "The roof of the cavern "
            "is lost in the darkness far overhead. But a massive "
            "cave in here has crushed the rest of the city under "
            "hundreds of thousands of tons of solid rock.",
        ({"cave in","collapse"}) : "The roof of the cavern has caved "
            "in, burying the rest of the city to the south. The massive "
            "wall of rock and rubble is completely impassable.",
        ]) );
    SetExits( ([ "north" : G_ROOM + "road16" ]) );
    SetInventory( ([
        G_OBJ + "fountain" : 1 ]) );
    }
