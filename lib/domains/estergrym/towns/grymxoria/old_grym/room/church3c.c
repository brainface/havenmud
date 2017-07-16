// Title: Destroyed Grymxoria Town
// File: church3c.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Cleric room of the Cathedral of Saahagoth
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
 
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(20);
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("the Church of Saahagoth");
    SetLong("This is the private chapel for the clerics of Saahagoth. "
        "There is a small altar at the end of the room. "
        "On one wall is a board for the clerics of grymxoria "
        "to discuss ideas for new spells. This room, amazingly "
        "enough, seems to be untouched.");
    SetExits( ([ "west" : G_ROOM + "church2c" ]) );
    SetItems( ([
        "altar" : "A small black stone altar with several religious "
            "items and small offerings on it."]) );
    }
