//
// An old mine shaft
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetShort("inside a mine shaft");
    SetLong("This long mine shaft drills deep into the mountain. Large "
      "wooden planks support the mine to prevent the mountain "
      "from caving in on the people inside. The rock on the wall "
      "looks very freshly drilled. On one end, the mine seems "
      "to stretch into eternal darkness inside the mountain, "
      "while on the other end, it leads to a bright and snowy "
      "valley outside. A tall steel grate to the east prevents "
      "the passage of anyone any further into the mine.");
    SetItems( ([ ({ "long mine shaft", "shaft", "long shaft",
	  "long mine", "mine shaft", }) : (: GetLong :),
	({ "dark mountain", "mountain" }) : "The mountain "
	"has gently been "
	"shaped around "
	"this mine, "
	"creating large "
	"rock walls to "
	"drill into.",
	({ "tall steel grate to the east",
	  "tall steel grate", "tall grate to the east",
	  "steel grate to the east", "large grate",
	  "steel grate", "grate" }) : "This tall steel grate "
	"sits on the eastern "
	"side of the mine, "
	"stopping anyone's "
	"attempt to "
	"penetrate into the "
	"mountain any "
	"further.",
	({ "large wooden planks", "large planks",
	  "large plank", "large wooden plank",
	  "wooden planks", "planks",
	  "plank", "wooden plank" }) : "These large wooden "
	"planks provide "
	"support for the "
	"mine to prevent "
	"its collapse.",
	({ "freshly drilled rock",
	  "rock" }) : "This rock covering the walls looks "
	"freshly drilled.",
	({ "shiny walls", "shiny wall",
	  "rock walls", "rock wall",
	  "walls", "wall" }) : "This wall looks shiny after "
	"being freshly drilled.",
	({ "bright and snowy valley", "snowy valley",
	  "valley", "bright valley" }) : "The snowy valley "
	"outside provides "
	"light and a way "
	"to get out of the "
	"large mine." ]) );
    SetExits( ([ "out" : ROOM "/valley" ]) );
    SetInventory( ([ NPC "/miner" : 3 ]) );
}
