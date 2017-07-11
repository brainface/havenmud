// Title: Destroyed Grymxoria Town
// File: road20.c
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
    SetLong("At the edge of the ruins of the city's business "
        "quarter. Abyss lane, named after the huge black pit "
        "that it passes, ends against the rubble that was "
        "once the city wall here. Beyond only darkness can be "
        "seen. The remains of the Grymxoria City Post Office "
        "can be seen to the west. To the south, the hulking "
        "ruin of the Grymxoria library can be seen, its "
        "crumbling gothic spires still looming up into the air. "
        "On either side of the road are decaying husks "
        "of what were once businesses and homes, now crumbling "
        "slowly into the street. Here and there are scattered "
        "smashed and spoiled peices of what might have once been "
        "wares sold by these shops.");
    SetExits( ([ "west" : G_ROOM + "road19"]) );
    SetItems( ([
        "library" : "The Grymxoria library. It is a large stone "
            "building of gothic construction. The crumbling remains "
            "of its tall gothic spires still loom high up into the "
            "air. The front of the building is collapsed, making it "
            "impossible to enter.",
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
    }
