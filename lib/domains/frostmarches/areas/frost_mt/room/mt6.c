//
// mt6.c
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
    SetLong("The thick snow here completely covers the ground, "
      "making the actual ground hard to find. To the northeast, "
      "a flat, snowless area sits as an entrance into a wide "
      "valley while to the southwest, the mountain becomes "
      "rockier and more unstable in an effort to swiftly climb to "
      "the top.");
    SetItems( ([ ({ "thick snow", "snow" }) : "The thick snow here "
	"completely covers "
	"the ground, making "
	"the actual ground hard "
	"to find.",
	({ "ground covered in snow",
	  "ground" }) : "The ground here is completely "
	"covered in thick snow.",
	({ "flat, snowless area", "snowless area",
	  "flat area", "area" }) : "This flat area to the "
	"northeast provides an "
	"easy entrance into the "
	"valley. There seems to "
	"be almost no snow on the "
	"ground at all.",
	({ "entrance to the valley",
	  "entrance" }) : "The entrance to the valley "
	"resides to the northeast.",
	({ "wide valley", "valley" }) : "This wide valley "
	"sits deep inside "
	"the middle of the "
	"mountain.",
	({ "top",
	  "mountain" }) : "This mountain dips down and "
	"surges upward in various "
	"directions." ]) );
    SetInventory( ([ NPC "/caribou" : random(2),
	NPC "/wolf" : random(2),
	NPC "/bear" : random(2) ]) );
SetObviousExits("northeast, southwest");
SetExits( ([ "northeast" : ROOM "/mt5",
    "southwest" : ROOM "/mt7" ]) );
}
