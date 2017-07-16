// Title: Destroyed Grymxoria Town
// File: road13.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Abyss Lane in Grymxoria
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(0);
    SetTown("Grymxoria");
    SetShort("Abyss lane");
    SetDomain("Estergrym");
    SetLong("This is the heart of the ruins of the city's business "
        "quarter. Abyss lane, named after the black pit that "
        "it passes, continues to the east and west. To the "
        "north is the rubble of what was once the Grymxoria "
        "bank. To the west looms the remains of the Grymxoria "
        "arena. On either side of the road are decaying husks "
        "of what were once businesses and homes, now crumbling "
        "slowly into the street. Here and there are scattered "
        "smashed and spoiled peices of what might have once been "
        "wares sold by these shops.");
    SetItems( ([
        ({ "arena", "grymxoria arena" }) : "A huge circular "
            "building made of black stone blocks, now "
            "crumbling slowly in on itself, huge piles of rubble "
            "leaning against its walls.",
        ({ "bank", "grymxoria bank" }) : "Nothing remains "
            "of the bank but a heap of rubble and scattered "
            "timbers.",
        ({"decaying husks","businesses","homes"}) : "On either side of "
            "the street are many buildings that might have once "
            "housed businesses or homes of wealthy citizens. Now they "
            "are little more than shells, slowly crumbling and adding "
            "to the heaps of rubble in the street.",
        ({"spoiled peices","peices","wares"}) : "Here and there a "
            "smashed peice of furnature, or a shredded length of cloth, "
            "and assorted other unidentifiable chunks of what were "
            "once people's possessions.",
        ]) );
    SetExits( ([ "east" : G_ROOM + "road14",
        "west" : G_ROOM + "road12"]) );
    }
