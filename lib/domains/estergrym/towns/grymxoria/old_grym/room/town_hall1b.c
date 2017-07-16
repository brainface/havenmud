// Title: Destroyed Grymxoria Town
// File: town_hall1b.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Library in the town hall of Grymxoria
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
    SetShort("a library in the Town Hall of Grymxoria");
    SetLong("This is what was once a small library in the "
        "western wing of the Grymxoria Town Hall. Now the "
        "Daemons have taken up residence here, and most of the "
        "bookshelves have been toppled and their contents strewn "
        "about the place. All around is the evidence of the "
        "Daemons, piles of filthy bedding and heaps of bones.");
    SetItems( ([
        ({"bookshelves","shelves"}) : "The bookshelves that once "
            "lined the walls of this room have been mostly knocked "
            "over, many of them broken up for firewood.",
        ({"book","books"}) : "The books from the shelves have been "
            "dumped out and hurled randomly about the room, many "
            "have been ripped or slashed.",
        ({"bedding piles","piles of bedding","piles","bedding"}) :
            "Piles of filthy bedding lay all about the room, "
            "giving testimony to the Deamon's residence here.",
        ({"heaps of bones","bone heaps","bones","heaps"}) :
            "Scattered about the room are piles of bones, reminants "
            "of past meals. The bones appear to be of all types and "
            "sizes, but the majority seem to be Nosferatu in origin.",
        ]) );
    SetExits( ([
        "north" : G_ROOM + "church1b",
        "east" : G_ROOM + "town_hall2b",
        "down" : G_ROOM + "town_hall1a",
        ]) );
    SetInventory(  ([
/*
        G_NPC "daemon" : 1 + random(3),
*/
	    ])  );
    }
