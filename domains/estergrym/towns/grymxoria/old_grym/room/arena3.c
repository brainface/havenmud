// Title: Destroyed Grymxoria Town
// File: arena1.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Destroyed Barbarian and Fighter lounge
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("the Grymxoria fighter's lounge");
    SetLong("At one end of the room is a large bar that has "
        "been splintered in several places. Scattered across "
        "the room are several ruined round wooden tables and "
        "shattered chairs, all covered in thick dust. On one "
        "wall is the shredded remains of a large bulletin board.");
    SetExits( ([
        "west" : G_ROOM + "arena2"]) );
    SetClimate("indoors");
    SetAmbientLight(0);
    SetItems( ([
        ({"bar"}) : "The long hard-wood bar has been splintered "
            "in many places, as if a good deal of heavy items "
            "were hurled violently against it.",
        ({"round tables","round table","wooden tables","wooden table",
        "table","tables","chair","chairs"}) : "Scattered around "
            "the room are several round wooden tables that have been "
            "thoroughly destroyed, as well as a dozen chairs that have "
            "been hurled about the room and smashed into peices.",
        ({"bulletin board","board","large board"}) : "The large bulletin "
            "board once held the rantings of the fighters that visited "
            "this lounge, but has been shredded beyond recognition.",
        ]) );
    }
