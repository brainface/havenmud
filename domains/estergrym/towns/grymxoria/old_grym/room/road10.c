// Title: Destroyed Grymxoria Town
// File: road10.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Blood River Road in Grymxoria
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
    SetDomain("Estergrym");
    SetShort("Blood River road");
    SetLong("Blood  River road continues to the north and south. "
        "The Blood river flows down the center of the two lane "
        "Blood River road from north to south. Looming up in the "
        "darkness to the south the huge gothic style cathedral "
        "of Saa'HaGoth can be seen. To the west is the Grymxoria "
        "cemetery. All around are the crumbling remains of buildings, "
        "the rubble of which chokes the street.");
    SetItems( ([
        ({ "river", "blood river", "Blood river" }) : "The blood "
            "river flows down the center of the divided two "
            "lane road. It gets its name from the reddish "
            "color of the water from the large amounts of iron "
            "and copper in it.",
        ({ "cathedral", "church" }) : "The cathedral looms "
            "up to the south. Its tallest spire has fallen as though "
	    "a great earthquake shook the foundation of the city. Colored "
            "patches of light can be seen shining eerily "
            "through the stained glass windows of the cathedral.",
        "cemetery" : "The Grymxoria cemetery, in the darkness, "
            "only the faint outline of large tombs can be seen.",
        ({"crumbling buildings","buildings","rubble"}) :
            "Crumbling husks of buildings line the street, and the "
            "rubble falling from them chokes the streets, making "
            "travel difficult.",
        ]) );
    SetListen( ([
        "default" : "The river swishes and gurgles eerily."]) );
    SetExits( ([ "north" : G_ROOM + "road06",
        "south" : G_ROOM + "road11"]) );
    SetEnters( ([
        "cemetery" : G_ROOM + "cemetary"]) );
    }
