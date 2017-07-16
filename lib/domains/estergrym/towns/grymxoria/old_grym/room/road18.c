// Title: Destroyed Grymxoria Town
// File: road18.c
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
    SetLong("Abyss lane continues to the east and west. "
        "Looming up in the darkness to the northwest the huge "
        "gothic style cathedral of Saa'HaGoth can be seen. "
        "And to the southwest the Town Hall building. "
        "To the east the Grymxoria Post Office can be seen. "
        "On either side of the road are decaying husks "
        "of what were once businesses and homes, now crumbling "
        "slowly into the street. Here and there are scattered "
        "smashed and spoiled pieces of what might have once been "
        "wares sold by these shops.");
    SetItems( ([
        ({"decaying husks","businesses","homes"}) : "On either side of "
            "the street are many buildings that might have once "
            "housed businesses or homes of wealthy citizens. Now they "
            "are little more than shells, slowly crumbling and adding "
            "to the heaps of rubble in the street.",
        ({"spoiled pieces","pieces","wares"}) : "Here and there a "
            "smashed piece of furnature, or a shredded length of cloth, "
            "and assorted other unidentifiable chunks of what were "
            "once people's possessions.",
        ({ "cathedral", "church" }) : "The cathedral looms up to "
            "the south. Its tallest spire has fallen as though an earthquake "
	    "has shaken the very foundation of the city. Colored patches of "
	    "light can be seen shining eerily through the stained glass "
	    "windows of the cathedral.",
        ({ "hall", "town hall" }) : "A large stone block building "
            "similar in architecture to the church, but not quite as "
            "large.",
        "post office" : "The grymxoria Post Office. It is an "
            "unremarkable building of the typical stone construction. "
            "Hung over the door is a sign reading: 'Grymxoria City Post "
            "Office.",
        ]) );
    SetExits( ([ "east" : G_ROOM + "road19",
        "west" : G_ROOM + "road17"]) );
    }
