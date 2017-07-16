// Title: Destroyed Grymxoria Town
// File: town_hall1a.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Entrance to the former Grymxoria town hall
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
    SetShort("the former Town Hall of Grymxoria");
    SetLong("This is the southwestern part of what was once "
        "the Grymxoria town hall. This room used to be a "
        "large waiting room, but it has now been converted "
        "into a guardroom where Daemon guards may keep "
        "watch and keep undesirables out of the complext. "
        "There is a set of stone stairs leading up.");
    SetItems( ([
        ({ "stair", "stair case" }) : "A stair case of "
            "black stone, leading up."]) );
    SetExits( ([ "out" : G_ROOM + "road15",
        "up" : G_ROOM + "town_hall1b"]) );
    SetInventory( ([
/*
        G_NPC + "guard" : 1 + random(3),
*/
        ]) );
    }
