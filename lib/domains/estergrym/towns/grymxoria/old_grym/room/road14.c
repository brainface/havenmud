// Title: Destroyed Grymxoria Town
// File: road14.c
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
        "quarter. Abyss lane, named after the black pit "
        "it passes, continues to the east and west. "
        "Looming up in the darkness to the northeast the huge "
        "gothic style cathedral of Saa'HaGoth can be seen.  "
        "And to the southeast the Town Hall building. "
        "To the west the ruins of the Grymxoria Bank can be "
        "seen. On either side of the road are decaying husks "
        "of what were once businesses and homes, now crumbling "
        "slowly into the street. Here and there are scattered "
        "smashed and spoiled peices of what might have once been "
        "wares sold by these shops.");
    SetItems( ([
        ({"decaying husks","businesses","homes"}) : "On either side of "
            "the street are many buildings that might have once "
            "housed businesses or homes of wealthy citizens. Now they "
            "are little more than shells, slowly crumbling and adding "
            "to the heaps of rubble in the street.",
        ({"spoiled peices","peices","wares"}) : "Here and there a "
            "smashed peice of furnature, or a shredded length of cloth, "
            "and assorted other unidentifiable chunks of what were "
            "once people's possessions.",
        ({ "cathedral", "church" }) : "The cathedral looms up to the "
		"north. Its tallest spire has fallen in on itself as if "
		"an earthquake shook the very foundations of the city. "
		"Colored patches of light can be seen shining eerily "
		"through the stained glass windows of the cathedral. "
		"Amazingly enough, it seems to be completely intact.",
        "cemetery" : "The Grymxoria cemetery, in the darkness, "
            "only the faint outline of large tombs can be seen.",
        ({ "hall", "town hall" }) : "A large stone block "
            "building similar in architecture to the "
            "church, but not quite as large.",
        ]) );
    SetExits( ([ "east" : G_ROOM + "road15",
        "west" : G_ROOM + "road13"]) );
    }
