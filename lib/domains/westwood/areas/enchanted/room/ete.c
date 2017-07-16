// Amelia@Haven

#include <lib.h>
inherit LIB_FISHING;
#include "../balz.h"

static void create() {
   fishing::create();
   
   SetShort("a small pool");
   SetLong("The trees above spread apart here, letting light seep through "
           "and hit a small pool here.  A little stream runs through "
           "the trees, stirring up the pool some so it doesn't become "
           "stagnant.  More gaps appear in the trees to walk through "
           "to the southeast, south, southwest, and west.");
   SetItems( ([
                ({ "large trees","trees","tree","large tree" }) :
                   "The trees densely fill all the area around here, but "
                   "have left a gap straight above, allowing the pool "
                   "to be healthy and clean.  Small drops of water fall "
		   "from the trees into the pool.",
                ({ "small pool","pool","water","drops","drop","drop of water",
		   "drops of water" }) :
                   "Waves ripple through the pool, originating from the "
		   "little stream that feeds it, as well as from "
		   "individual drops of water falling from the trees.",
                ({ "little stream","stream" }) :
                   "The little stream tinkles along quietly.",
                ({ "small gaps","gaps","gap" }) :
                   "Gaps in the trees appear to the southeast, south, "
                   "southwest, and west for one to move through.",
           ]) );
   SetListen( ([
		"default" : "Holding a steady rhythm, drops of water "
			"fall into the pool.",
	]) );
   SetSmell( ([
		"default" : "The air is fairly fresh here, though a small "
			"hint of decay can be decated.",
	]) );
   SetExits( ([
                "west" : B_ROOM + "/etd",
                "south" : B_ROOM + "/etc",
                "southwest" : B_ROOM + "/etb",
                "southeast" : B_ROOM + "/eta",
           ]) );
   SetSpeed(5);
   SetFish( ([ B_NPC + "/fish" : 90 ]) );
   SetChance(25);
   SetMaxFishing(12);
   SetInventory( ([
                    B_NPC + "/treea" : random(3)+1,
               ]) );
}