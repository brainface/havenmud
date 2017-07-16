//
// mt4.c
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("arctic");
    SetDomain("FrostMarches");
    SetShort("in the FrostMarches");
    SetLong("The snow here looks freshly fallen from a typical "
      "winter's storm in these mountains. The terrain here "
      "is smooth as well. A valley is a short distance below "
      "here, down a small cliff. To the southeast, the terrain "
      "become more unstable as it climbs higher into the sky. "
      "To the northwest, the terrain flattens out smoothly and "
      "the snow disappears almost completely as "
      "it provides an entrance to the valley.");
    SetItems( ([ ({ "fresh snow",
	  "snow" }) : "This fresh snow sits on the ground "
	"molding to the smooth terrain here.",
	({ "smooth terrain",
	  "terrain" }) : "This terrain here is smooth, almost "
	"completely covered by snow.",
	({ "large valley",
	  "valley" }) : "Down a small cliff, the valley sits "
	"very invitingly.",
	({ "small cliff", "cliff" }) : "This small cliff leads "
	"straight down into the "
	"valley below.",
	({ "mountains",
	  "mountain" }) : "This large mountain stretches in "
	"many directions, dipping and "
	"climbing in various ways." ]) );
    SetObviousExits("northwest, southeast");
    SetExits( ([ "northwest" : ROOM "/mt5",
	"southeast" : ROOM "/mt3" ]) );
    SetInventory( ([ NPC "/caribou" : 1 ]) );
}
