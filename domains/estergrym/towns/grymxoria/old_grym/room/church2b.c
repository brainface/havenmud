// Title: Destroyed Grymxoria Town
// File: church2b.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Central Chapel of the Saahagoth Cathedral
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
    SetLong("This is the central room of the second level of the "
        "Cathedral of Saahagoth. All around is the evidence of the "
        "Daemons that have been living here. Ragged beds in the "
        "corners and piles of bones scattered around. Looking out "
        "of the large, leaded glass windows, the central courtyard "
        "of the church complex can be seen. The blackness of the "
        "mouth of the Abyss yawns open like it could swallow the "
        "world.  There is a desecrated shrine to the north. There "
        "appears to have been a large stair case leading up but it is "
	"now destroyed beyond use.");
    SetExits( ([ "west" : G_ROOM + "church1b",
	    "north" : G_ROOM + "thorian_shrine",
      "up" : G_ROOM + "church2c",
        "east" : G_ROOM + "church3b",
	]) );
    SetItems( ([
        ({"bed","beds"}) : "There are ragged heaps of bedding "
            "material in corners of the room and along the walls.",
        ({"piles","pile"}) : "Piles of bones are scattered about "
            "the room from the Daemons meals. They appear to be "
            "of all types and sizes, but a good deal seem to be "
            "Nosferatu in origin.",
        ({"windows","window"}) : "These large windows keep the "
            "cold cavern air and whatever flying pests are outside "
            "out of the Cathedral while allowing one to look out "
            "at the courtyard far below. Looking out through it "
       "you can see the Center of Grymxoria.",
            ({"stair","staircase","stairs"}) : "A large stone "
            "staircase leads up to the floor above.",
        ]) );
    SetItemAdjectives( ([
        "bed" : "ragged",
        "piles" : "bone",
        "windows" : ({"large","leaded","glass"}),
        ]) );
    SetInventory( ([
        ]) );
    }
