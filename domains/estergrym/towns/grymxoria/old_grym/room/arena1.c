// Title: Destroyed Grymxoria Town
// File: arena1.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Grymxoria Arena
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
inherit LIB_ROOM;
#include "../grymxoria.h"

static void create() {
    room::create();
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("the Grymxoria arena practice room");
    SetLong("This is a large room with a bare stone floor. Lined along the walls are "
        "destroyed racks that used to hold weapons and armour. The weapons and "
        "armour are now scattered about the room, horribly bent and dented, "
        "most rusting. The gladiators of Grymxoria used to practice their "
        "fighting techniques here, until they were slaughtered by the Daemons. "
        "The flagstones in the floor sport an occasional brownish red spot or "
        "splash, as well as two large stains that spill across the floor. "
        "Additionally, everything in the room is covered in a thick layer of "
        "dust.");
    SetItems( ([
        ({"floor", "spot", "spots", "splash", "splashes", "flagstones", "stone",
            "stone floor","stain","stains"}) : "A bare floor of rectangular "
            "gray flagstones. Here and there is a brownish red splash or spot "
            "that is probably blood as well as two large stains that spill across "
            "the floor, that are undoubtedly blood, and lots of it.",
        ({"rack", "racks" }) : "Along the walls are destroyed racks that once "
            "held weapons and armour.",
        ({"weapon","weapons","armour","armours"}) : "Various types of weapons and "
            "armour are scattered about the room, all of them smashed and bent "
            "beyond recognition.",    
        ]) );
    SetExits( ([
        "east" : G_ROOM + "arena2"]) );
    SetClimate("indoors");
    SetAmbientLight(0);
    }
