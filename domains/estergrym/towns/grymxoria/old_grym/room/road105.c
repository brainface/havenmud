#include <lib.h>
#include <domains.h>
#include "../grymxoria.h"
#define CAVE "/domains/estergrym/areas/amelia_caves/room/"
inherit LIB_ROOM;
static void create() {
room::create();
        SetDomain("Estergrym");
        SetShort("A road inside the Estergrym Mountains");
        SetLong("This small cobblestone road is going deep into the "
		"Estergrym Mountains. The terrain here crumbles under "
		"whoever walks on it making it very dangerous. The "
		"small road here continues east into a small tunnel, north "
		"into caves as well as down and west onto other roads.");
        SetItems( ([ ({ "road", "cobblestone road" }) : "This nicely made "
		"cobblestone road heads up and down.",
		"tunnel" : "This small tunnel runs through the mountain.",
		({ "mountains", "estergrym mountains" }) : "This mountain "
			"is in the north eastern part of the world.",
		"terrain" : "The terrain here is very rough and unstable." ]) );
        SetExits( ([ "east" : G_ROOM + "road104",
           "down" : ESTERGRYM_VIRTUAL "estergrym_road/0,250",
          "up" : ESTERGRYM_AREAS "lake/room/road1",
			   "west" : G_ROOM + "road106",
                ]) );
        AddExit("north", CAVE + "rooma" );
}
