// Title: Destroyed Grymxoria Town
// File: road02.c
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
    SetLong("The beginning of the Blood River road. "
        "The shattered ruins of the city gates are immediately to the "
        "north, and the road runs away to the south. The Blood "
        "River runs down the center of the large, two lane road. "
        "To the east is the remains of the Grymxoria city barracks.");
    SetItems( ([
        ({ "gate", "gates", "city gates" }) : "The ruins of the "
            "gates to the city are close by to the north.",
        ({ "river", "blood river", "Blood River" }) : "The "
            "Blood River flows down the center of the divided "
            "two lane road. It gets its name from the reddish "
            "color of the water from the large amounts of iron "
            "and copper in it.",
        ({ "barracks", "building" }) : "The ruins of a large "
            "stone building that at one time was built like a "
            "fortress. It used to look like it could withstand "
            "any assault, apparently could not."]) );
    SetListen( ([
        "default" : "The river swishes and gurgles eerily."]) );
    SetExits( ([ "north" : G_ROOM + "road01",
        "south" : G_ROOM + "road06"]) );
    SetEnters( ([ "barracks" : G_ROOM + "barrack1" ]) );
    }
