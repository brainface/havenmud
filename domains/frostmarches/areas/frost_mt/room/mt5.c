//
// mt5.c
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
    SetShort("an entrance to a large valley");
    SetLong("Here the terrain is rough, covered by almost no snow "
      "at all. Small twigs and sticks cover the dark and rocky "
      "ground here. To the south, the snow builds back up "
      "where a large valley "
      "sits peacefully, while to the southwest and southeast, "
      "snowy hills begin to climb high into the peaks of the "
      "mountain.");
    SetItems( ([ ({ "rough terrain", "rocky terrain", "ground",
	  "terrain" }) : "The rocky terrain here is covered "
	"by a thick layer of sticks and "
	"twigs.",
	({ "sticks and twigs", "twigs",
	  "blanket", "thick blanket",
	  "small sticks and twigs", "small sticks",
	  "small twigs", "small stick", "small twig",
	  "sticks", "stick", "twig" }) : "These small sticks "
	"and twigs make a "
	"thick blanket for "
	"the rocky terrain "
	"that resides here.",
	({ "thick snow",
	  "snow" }) : "In all directions, the snow begins to "
	"pile up and take over the terrain "
	"of the mountain.",
	({ "large valley", "valley" }) : "This large valley "
	"sits to the south, "
	"directly in the "
	"middle of the large "
	"cliffs surrounding "
	"it many directions.",
	({ "hills", "cliffs",
	  "hill", "cliff" }) : "These hills soar high "
	"into the mountains "
	"in an attempt to reach the "
	"snowy peaks.",
	({ "snowy peaks", "snowy peak",
	  "peak", "peaks" }) : "These snowy peaks "
	"stretch so high into "
	"the sky, they aren't "
	"completely visible "
	"from here.",
	({ "mountains",
	  "mountain" }) : "This large mountain stretches in "
	"many directions, dipping and "
	"climbing in various ways." ]) );
    SetInventory( ([ NPC "/wolf" : random(2)+1 ]) );
    SetObviousExits("south, southeast, southwest");
    SetExits( ([ "south" : ROOM "/valley",
	"southwest" : ROOM "/mt6",
	"southeast" : ROOM "/mt4" ]) );
}
