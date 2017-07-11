#include <lib.h>
#include "../grymxoria.h"
#define UNDERDARK "/domains/estergrym/areas/underdark/room/"
inherit LIB_ROOM;
static void create() {
room::create();
        SetDomain("Estergrym");
        SetShort("A road inside the Estergrym Mountains");
        SetLong("This small cobblestone road is going deep into the "
		"Estergrym Mountains. The terrain here crumbles under "
		"whoever walks on it making it very dangerous. The "
		"small road here continues east onto along small road, "
		"and west into caves.");
        SetItems( ([ ({ "road", "cobblestone road" }) : "This nicely made "
		"cobblestone road heads up and down.",
		"tunnel" : "This small tunnel runs through the mountain.",
		({ "mountains", "estergrym mountains" }) : "This mountain "
			"is in the north eastern part of the world.",
		"terrain" : "The terrain here is very rough and unstable." ]) );
        SetExits( ([ "east" : G_ROOM + "road105",
                ]) );
        AddExit("west", UNDERDARK + "room1a" );
}
