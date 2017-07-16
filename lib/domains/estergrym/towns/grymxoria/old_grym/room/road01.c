// Title: Destroyed Grymxoria Town
// File: road01.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Entrance to Grymxoria
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(0);
    SetTown("Grymxoria");
    SetDomain("Estergrym");
    SetShort("Grymxoria City Gate");
    SetLong("The tunnel opens up into a huge cavern. Passing "
        "under what was once an elaborately carved black "
        "stone arch, but is now just a defaced pile of rubble. "
        "Hung in the remains of the arch arch is a twisted "
        "and melted set of huge gates made of red metal. "
        "The Blood River passes through these gates, while "
        "pedestrians once had to go through one of the "
        "smaller doors on each side of the main gate, "
        "which both lie in ruins now. The Blood river "
        "follows the road named after it away to the "
        "south where the south the ruins of the Grymxoria "
        "city barracks can be seen.");
    SetExits( ([
        "south" : G_ROOM + "road02",
	"north" : G_ROOM + "road101",
	 ]) );
    SetItems( ([
        "arch" : "A huge ruined arch carved partially out "
            "of the living stone of the cavern. There are "
            "three doorways set in the arch. A large central "
            "one through which the Blood river passes. And "
            "two smaller gates, one to each side of the "
            "river, through which pedestrians were intended "
            "to pass. The entire construction is little more "
            "than rubble now.",
        "wall" : "The city wall of Grymxoria. It is made out "
            "of large roughly hewn stone blocks, stacked and "
            "mortared. It once looked strong enough to turn "
            "back any assault, but apparently wasn't.",
        ({ "gates", "huge gates" }) : "A set of huge gates made "
            "of a red metal. The Blood river passes through the "
            "opening between them. The gates seem to have been "
            "twisted and melted by some unimaginable force.",
        ({ "doors", "smaller doors" }) : "Two small gates, one to "
            "each side of the river. They were once hung with "
            "metal doors similar to the ones in the main gate, "
            "but have since been destroyed.",
        ({ "river", "blood river", "Blood river" }) :
            "The blood river flows down the center of the "
            "divided two lane road. It gets its name from "
            "the reddish color of the water from the large "
            "amounts of iron and copper in it."]) );
    SetListen( ([
        "default" : "The river swishes and gurgles eerily."]) );
    }
