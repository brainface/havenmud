// Title: Destroyed Grymxoria Town
// File: church1b.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Western Chapel of the Saahagoth Cathedral
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
    SetLong("This used to be the western chapel of the Cathedral "
        "of Saahagoth. The Daemons have set up camp here, all around "
        "is evidence of their residence. What were once benches for "
        "worshipers have been made into beds for the Daemons, and all "
        "around are piles of bones, perhaps reminants of past meals, "
        "most of them appear to be Nosferatu bones. And there is a fire "
        "burning in a circle of stones in the center of the room."
        "All around, set in the walls, are large stain glass "
        "windows depicting the history of the Nosferatu, lit by "
        "some unknown source.");
    SetItems( ([
        ({"bench","benches","beds","bed"}) : "Long benches of carved "
            "black marble that have been transformed into beds and "
            "tables for the Daemons.",
        ({"wall","walls"}) : "Walls of large, roughly carved, "
            "black stone.",
        ({"windows","large windows","stain glass windows", 
            "large stain glass windows."}) : "These windows depict "
            "the history of the Nosferatu. Going from their early days "
            "as bloodthirsty hunters, through their exile into the "
            "depths of the earth.",
        ({"piles of bones","bones","pile of bones"}) : "Many piles "
            "of bones are scattered about the room. Probably reminants "
            "of past meals. There are bones of all types and sizes, "
            "but the majority appear to be Nosferatu in origin.",
        ({"fire pit","fire","circle of stones","circle","stones"}) :
            "A circle of stones, probably chunks of rubble, have been "
            "used to form a firepit.",
        ]) );
    SetExits( ([ "east" : G_ROOM + "church2b",
        "south" : G_ROOM + "town_hall1b",
        "down" : G_ROOM + "church1a"]) );
    SetInventory( ([
        ]) );
    }
