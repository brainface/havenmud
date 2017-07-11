#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("a curve in the swamp path");
	SetExits( ([
	  "north"      : GWONISH_ROOM "gw06",
	  "east"       : GWONISH_ROOM "gw02",
	  "southeast"  : GWONISH_ROOM "gw01",
	  ]) );
	SetLong(
	  "The swampy path meets in a three-direction point here, heading north "
	  "deeper into the swamp, southeast towards the open sea, and east into "
	  "the village. Deep, drooping trees hang over the path with their vines "
	  "seeming to strangle the life out of the swamp. A large rotting tree "
	  "lies in the middle of the path, seemingly a bench in a busy intersection."
	  );
	SetItems( ([
	  ({ "trees" }) : "The trees are drooping things with long, green vines.",
	  ({ "tree", "bench" })  : "The tree seems to serve as a bench.",
	  ({ "vine", "vines" }) : "The vines hang over the path.",
	  "path" : "The path is little more than a dry walkway through the swamp.",
	  ]) );
	SetItemAdjectives( ([
	  "trees" : ({ "deep", "drooping" }),
	  "tree" : ({ "large", "rotting" }),
	  ]) );
	SetSmell( ([
	  "default" : "The smell of rotting vegetation taints the swamp.",
	  ]) );
	SetListen( ([
	  "default" : "Wildlife chirps, caws, and slithers through the swamp.",
	  ]) );
	SetInventory( ([
	  ]) );  
}#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("a curve in the swamp path");
	SetExits( ([
	  "north"      : GWONISH_ROOM "gw06",
	  "east"       : GWONISH_ROOM "gw02",
	  "southeast"  : GWONISH_ROOM "gw01",
	  ]) );
	SetLong(
	  "The swampy path meets in a three-direction point here, heading north "
	  "deeper into the swamp, southeast towards the open sea, and east into "
	  "the village. Deep, drooping trees hang over the path with their vines "
	  "seeming to strangle the life out of the swamp. A large rotting tree "
	  "lies in the middle of the path, seemingly a bench in a busy intersection."
	  );
	SetItems( ([
	  ({ "trees" }) : "The trees are drooping things with long, green vines.",
	  ({ "tree", "bench" })  : "The tree seems to serve as a bench.",
	  ({ "vine", "vines" }) : "The vines hang over the path.",
	  "path" : "The path is little more than a dry walkway through the swamp.",
	  ]) );
	SetItemAdjectives( ([
	  "trees" : ({ "deep", "drooping" }),
	  "tree" : ({ "large", "rotting" }),
	  ]) );
	SetSmell( ([
	  "default" : "The smell of rotting vegetation taints the swamp.",
	  ]) );
	SetListen( ([
	  "default" : "Wildlife chirps, caws, and slithers through the swamp.",
	  ]) );
	SetInventory( ([
          GWONISH_NPC "sneak_trainer" : 1,
	  ]) );  
}
