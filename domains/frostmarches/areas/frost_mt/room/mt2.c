//
// mt2.c
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
    SetShort("high in the FrostMarches");
    SetLong("This area of the mountain stretches high into the sky. "
      "To the southwest, a white peak soars, while to the "
      "northeast, it gets slightly lower in altitude. A valley "
      "sits below to the west. To the east, a huge cliff "
      "falls sharply down to ground which is not visible from "
      "this height. The upper half of huge pine trees stick "
      "out of the ground to serve as an example of how deep "
      "the snow is here.");
    SetItems( ([ ({ "white peak", "white mountain",
	  "mountain", "peak" }) : "This mountain "
	"stretches into the sky "
	"with ease.",
	({ "the upper half of huge pine trees",
	  "the upper half of huge pine tree",
	  "upper half of huge pine trees",
	  "upper half of huge pine tree",
	  "upper half", "huge pine trees",
	  "pine tree", "tree",
	  "huge pine tree", "example", }) : "These large "
	"green pine trees "
	"stick out of the "
	"snowy ground "
	"only about half"
	"way to serve "
	"as an example "
	"of the great "
	"amount of snow "
	"on the ground.",
	({ "large valley",
	  "valley" }) : "This large valley to the west sits "
	"peacefully in the center of the "
	"mountain.",
	({ "huge cliff", "cliff" }) : "This huge cliff "
	"sharply falls down "
	"to ground that is "
	"not visible from "
	"here.",
	({ "low ground", "bottom of the cliff",
	  "bottom of cliff", "ground" }) : "The ground at "
	"the bottom of the "
	"cliff is not "
	"visible from this "
	"height." ]) );
    SetObviousExits("northeast, southwest");
    SetExits( ([ "northeast" : ROOM "/mt3",
	"southwest" : ROOM "/mt1" ]) );
}
