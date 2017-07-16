// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../balz.h"

static void create() {
   room::create();
   
   SetShort("a dark forest path");
   SetLong("Dark, knotted branches cover the sky above, making it "
           "difficult for light to filter down.  Broad tree trunks "
           "block the path and roots hide its presence, causing it "
           "to all but disappear.  The trees have curled to the side, "
           "bending their trunks and parting their branches, causing "
           "gaps in their thick coverage to the east, northeast, "
           "and north.");
   SetItems( ([
                ({ "dark knotted branches","dark branches","branches",
                   "dark knotted branch","dark branch","knotted branch",
                   "knotted branches","branch","large branches",
                   "blemishes","blemish","wood" }) :
                   "Thick, knotted blemishes appear all over the "
                   "wood of these trees, the branches interwined "
                   "above cradling the spots, some of which are "
                   "tinted with silver or gold.",
                ({ "broad tree trunks","broad trunks","trunks","trunk",
                   "tree trunks","broad tree trunk","broad trunk",
                   "tree trunk","forest trees","trees","tree","forest",
                   "wall","leaf","leaves" }) :
                   "Large branches arch out of the trunks of these "
                   "trees at all heights, looping and closed together, "
                   "creating what would be an impermeable wall all "
                   "around, if it were not for the few gaps.",
                ({ "tree roots","roots","root","ugly roots",
                   "ugly tree roots","dirt","soil" }) :
                   "Large, ugly tree roots grow across the ground, digging "
                   "into the dirt and loosening the soil.",
                ({ "forest path","path" }) :
                   "The forest path extends to the southeast.  Other "
                   "than that, it has disappeared.",
                ({ "small gaps","gaps","gap","thick coverage" }) :
                   "Gaps appear in three directions, the largest one "
                   "being to the north, with smaller ones to the northeast "
                   "and east.",
           ]) );
   SetListen( ([
		"default" : "A breeze shakes the leaves on the trees.",
		"tree" : "The sounds of the leaves shaking is reminiscent "
			"of metal windchimes.",
	]) );
   SetSmell( ([
		"default" : "There is a rank smell of decaying forest matter.",
	]) );
   SetExits( ([
                "east" : B_ROOM + "/etc",
                "northeast" : B_ROOM + "/ete",
                "north" : B_ROOM + "/etd",
           ]) );
   SetInventory( ([
                    B_NPC + "/treea" : random(2)+1,
                    B_NPC + "/treeb" : random(2)+1,
               ]) );
}