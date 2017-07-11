// Title: Destroyed Grymxoria Town
// File: church2a.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Eastern Entrance to the Cathedral of Saahagoth
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
    SetShort("the Cathedral of Saahagoth");
    SetLong("This is the northeastern part of the Cathedral of "
        "Saahagoth. This room used to be a sort of waiting area "
        "for visitors to the temple above, but has now been "
        "transformed into a sort of guard room, where several "
        "Daemon guards stand ready to deal with any unwanted "
        "intruders. In the corner of the room is a stone stair "
        "case leading up.");
    SetItems( ([
        "stone" : "Blocks of crudely shaped black stone.",
        ({ "stair", "stair case" }) : "A stair case of "
            "black stone, leading up."]) );
    SetListen( ([
        "default" : "Booming laughter and talking in Gryshnak "
            "can be heard from above."]) );
    SetExits( ([ "out" : G_ROOM + "road17",
        "up" : G_ROOM + "church3b"]) );
    SetInventory( ([
        ]) );
    }
