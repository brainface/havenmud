// Title: Destroyed Grymxoria Town
// File: road19.c
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
    SetClimate("indoors");
    SetAmbientLight(0);
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("Abyss lane");
    SetLong("This is the heart of the ruins of the city's business quarter. "
        "Abyss lane, named after the black pit that it passes, "
        "continues to the east and west. To the north is a "
        "destroyed stone building with a thrashed sign "
        "that still proclaims it 'Grymxoria City Post "
        "Office'. To the east the ruins of the Grymxoria library "
        "can be seen, looming up into the air. "
        "On either side of the road are decaying husks "
        "of what were once businesses and homes, now crumbling "
        "slowly into the street. Here and there are scattered "
        "smashed and spoiled peices of what might have once been "
        "wares sold by these shops.");
    SetItems( ([
        "post office" : "The grymxoria Post Office. It is a "
            "destroyed building of stone that now lies in a pile "
            "of rubble.  Laying on the ground is a sign reading: "
	    "Grymxoria City Post Office.",
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
    SetExits( ([ "east" : G_ROOM + "road20",
        "west" : G_ROOM + "road18"]) );
    }
