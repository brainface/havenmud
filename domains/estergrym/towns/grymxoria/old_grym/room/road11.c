// Title: Destroyed Grymxoria Town
// File: road11.c
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
        "south and partially to each side is the huge gothic style "
        "cathedral of Saa'HaGoth. Where the cathedral straddles "
        "the road a large archway is set leading to the south. "
        "It opens into the huge central courtyard of the church "
        "and town hall complex. To the north is the Grymxoria "
        "Cemetery.");
    SetItems( ([
        ({ "river", "blood river", "Blood river" }) : "The blood "
            "river flows down the center of the divided "
            "two lane road. It gets its name from the "
            "reddish color of the water from the large "
            "amounts of iron and copper in it.",
        ({ "cathedral", "church" }) : "The cathedral "
            "looms up above. Its tallest spire has fallen as though the "
	    "foundation of the city were shaken by an earthquake. Colored "
            "patches of light can be seen shining eerily "
            "through the stained glass windows of the "
            "cathedral. Large stone gargoyles sit on ledges "
            "looking down on the road. Amazingly enough, the "
            "cathedral seems to be completely intact.",
        "gargoyles" : "Large black stone gargoyles, their "
            "faces carved in grotesque and frightening "
            "expressions, watch over the cathedral. In the "
            "darkness it looks almost as if their eyes move "
            "to watch people passing beneath the arch."]) );
    SetListen( ([
        "default" : "The river swishes and gurgles eerily."]) );
    SetExits( ([ "north" : G_ROOM + "road10",
        "south" : G_ROOM + "road16"]) );
    }
