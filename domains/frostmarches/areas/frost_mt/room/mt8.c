//
// mt8.c
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
    SetLong("This part of the mountain sits high in the sky. To the "
      "southeast, a huge peak sits. To the northwest, the "
      "ground becomes slightly lower in altitude. A large "
      "cliff here to the east looms over a valley in "
      "the center of the mountain. Small puddles of water "
      "are in the ground here. A small sheen of ice covers them, "
      "just enough to give off a bright reflection.");
    SetItems( ([ ({ "frostmarches", "FrostMarches",
	  "mountain", "ground" }) : (: GetLong :),
	({ "puddles of water", "puddles", "water puddles",
	  "puddles", "water puddles",
	  "puddle of water" }) : "These small puddles of "
	"water indent the ground, "
	"growing with every "
	"drop of melting snow.",
	({ "ice in the puddles", "ice in the puddle",
	  "sheen of ice", "sheen", 
	  "ice" }) : "A small layer of ice covers each puddle "
	"casting a bright reflection off of its "
	"surface.",
	({ "bright reflections", "bright reflection",
	  "reflections", "reflection" }) : "These reflections "
	"are of whomever "
	"is looking "
	"directly at the "
	"ice in the "
	"puddles.",
	({ "huge peak", "peak" }) : "This peak to the "
	"southeast is one of the "
	"largest on the entire "
	"mountain.",
	({ "rocky ground",
	  "ground" }) : "The ground here is very rocky and "
	"dangerous to walk on.",
	({ "large cliff", "cliff" }) : "This large cliff looms "
	"a valley below.",
	({ "center valley",
	  "valley" }) : "This valley in the center of the "
	"mountain sits peacefully." ]) );
    SetObviousExits("northwest, southeast");
    SetExits( ([ "northwest" : ROOM "/mt7",
	"southeast" : ROOM "/mt1" ]) );
    SetInventory( ([ NPC "/bear" : 1,
	NPC "/caribou" : random(2) ]) );
}
