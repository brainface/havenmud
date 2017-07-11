// Title: Destroyed Grymxoria Town
// File: road12.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Abyss Lane Road in Grymxoria
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
    SetLong("At the edge of the ruins of the city's business "
        "quarter. Abyss lane, named after the huge black pit "
        "that it passes, ends against the city wall here. "
        "Beyond only darkness can be seen. The rubble that was "
        "once the Grymxoria bank can be seen to the east. "
        "While to the south the huge shell of the Grymxoria "
        "arena looms up. On either side of the road are decaying "
        "husks of what were once businesses and homes, now crumbling "
        "slowly into the street. Here and there are scattered "
        "smashed and spoiled peices of what might have once been "
        "wares sold by these shops.");
    SetItems( ([
        ({ "arena", "grymxoria arena" }) : "A huge circular "
            "building made of black stone blocks, now "
            "crumbling slowly in on itself, huge piles of rubble "
            "leaning against its walls.",
        ({"bank","grymxoria bank"}) : "The crumbling husk of what "
            "was once the Grymxoria City Bank can be seen to the "
            "east.",
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
    SetObviousExits("east");
    SetExits( ([ "east" : G_ROOM + "road13"]) );
    SetEnters( ([ "arena" : G_ROOM + "arena2" ]) );
    }
