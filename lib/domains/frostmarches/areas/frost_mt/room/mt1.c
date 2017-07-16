//
// mt1.c
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
    SetShort("atop a large peak in the FrostMarches");
    SetLong("The snowy ground here at the top of this large peak in "
      "the FrostMarches is whiter than anyone could belive. "
      "A small, wooden ladder here provides access to the valley "
      "deep inside the mountains. To the south, the outskirts "
      "of a town reside, while to the northeast and northwest, "
      "the mountain continues, snowy and cold.");
    SetObviousExits("northwest, northeast, south");
    SetExits( ([ "northwest" : ROOM "/mt8",
	"northeast" : ROOM "/mt2",
     "south" : "/domains/frostmarches/towns/keryth/room/outskirt"]) );
    SetItems( ([ ({ "snowy ground", "ground" }) : "This ground is "
	"extremely snowy "
	"and white.",
	({ "outskirt of a town", "outskirts of a town",
	  "outskirts", "outskirt" }) : "The small outskirts "
	"of a mountain city "
	"resides to the south.",
	({ "shiny, white peaks", "shiny, white peak",
	  "mighty peaks", "mighty peak",
	  "white peaks", "shiny peaks",  "white peak",
	  "shiny peak", "large peaks", "large peak",
	  "peaks","peak" }) : "These large peaks sit "
	"atop the FrostMarches.",
	({ "mountain", "mountains",
	  "Marches", "FrostMarches",
	  "marches", "frostmarches" }) : "This large "
	"mountain stretches "
	"into the sky with "
	"its shiny, white "
	"peaks.",
	({ "snowy valley",
	  "valley" }) : "This snowy valley rests far below "
	"these mighty peaks.",
	({ "soft snow", "fluffy snow",
	  "snow" }) : "The snow looks very soft and "
	"fluffy." ]) );
    SetInventory( ([ OBJ "/ladder" : 1,
	NPC "/wolf" : random(3) ]) );
}
