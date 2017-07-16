//
// mt7.c
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
    SetLong("This western tip of the mountain provides thin ground "
      "to walk on. Snow is constantly falling off and pounding "
      "into the valley below, building its supply of the white "
      "powder. To the southeast, the mountain becomes "
      "very rocky, while to the northeast, the ground smoothes "
      "out somewhat.");
    SetItems( ([ ({ "large mountain", "mountain" }) : (: GetLong :),
	({ "white powder", "powder", 
	  "snow" }) : "This deep, white powder seems "
	"to never run out of supply.",
	({ "snowy valley",
	  "valley" }) : "This valley rests in the center of "
	"the mountain, blanketed in a thick "
	"layer of snow.",
	({ "submerged ground",
	  "ground" }) : "The ground on this entire "
	"mountain is almost completely "
	"submerged in snow.",
	({ "western tip", "tip" }) : "This western tip of "
	"the mountain is "
	"very dangerous as there "
	"is not much of a tip "
	"to walk on." ]) );
    SetObviousExits("northeast, southeast");
    SetExits( ([ "northeast" : ROOM "/mt6",
	"southeast" : ROOM "/mt8" ]) );
    SetInventory( ([ NPC "/wolf" : 1,
	NPC "/explorer" : 1 ]) );
}
