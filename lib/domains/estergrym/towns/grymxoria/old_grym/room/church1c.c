// Title: Destroyed Grymxoria Town
// File: church1c.c
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
    SetLong("this is the inner sanctum of the clerics of Saahagoth.  "
        "The black stone walls are hung with large tapestries. "
        "There are stone benches lining the walls, and a small "
        "fountain of water piped directly from the pure and holy "
        "Blood River. It appears that the Daemons were unable "
        "to get in this room because it is relatively prestine.");
    SetExits( ([ "east" : G_ROOM + "church2c" ]) );
    SetItems( ([
        "tapestries" : "Large, rich tapestries depicting some of the "
            "many triumphs of the Nosferatu in purifying the world.",
        ({ "bench", "benches" }) : "Benches carved of black marble "
            "line the walls",
        "fountain" : "A small stone fountain of a simple design. "
            "The red water of the pure and holy blood river flows into a "
            "basin, and then back through a pipe to the river."]) );
  }

