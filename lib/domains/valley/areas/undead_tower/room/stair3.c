//*       Created by Severen        *//
//*            stair3.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("on a lower staircase");
    SetLong(
      "This is a lower part of the staircase. A doorway stands here "
      "providing entrance to another part of the tower. There is a "
      "symbol above the doorway. The steps of the staircase are "
      "considerably worn here and it is a long drop to the bottom of "
      "the tower. Grey stone make up the walls of the tower and it "
      "looks as if they would crumble to the touch. There is a door"
      "way further up and down the staircase."
    );

    SetItems(([
	({"tower"}) :
	(: GetLong :),
	({"walls","wall"}) :
	"They form a circular room and are made of the same grey stone that "
	"the rest of the tower is made of. A staircase spirals up and down it.",
	({"stone"}) :
	"Grey stone that looks like it would crumble at the touch.",
	({"floor"}) :
	"A decent drop to the bottom floor.",
	({"drop"}) :
	"It is a long way down to the floor of the tower.",
	({"below"}) :
	"The rest of the staircase going down.",
	({"top"}) :
	"The top of the staircase is a winding climb.",
	({"part"}) :
	"This is the lower part of the staircase.",
	({"doorway"}) :
	"A door is here with a strange symbol above it.",
	({"symbol"}) :
	"A strange symbol marks the nature of this entrance. "
	"It is of a triangle with an eye in its center.",
	({"steps","stairs"}) :
	"A magnificent work of craftsmanship, the staircase looks as if "
	"it was carved out of the walls themselves. It does look very old "
	"and caution should be used climbing it. Noticeable is a door higher "
	"up and further down the staircase.",
      ]));

    SetItemAdjectives(([
	"tower" : ({"ancient","old","dull"}),
	"walls" : ({"dull","grey","stone","circular"}),
	"stone" : ({"dull","grey"}),
	"stairs" : ({"magnificent","old","grey","spiraling","carved",
	  "badly","worn"}),
	"floor" : ({"bottom"}),
	"part" : ({"lower"}),
	"symbol" : ({"strange"}),
      ]));

    SetSmell("default","The stench of blood can be smelled here.");

    SetObviousExits("doorway");

    SetEnters(([
	"doorway" : TROOM + "/room1b",
      ]));

    SetDoor("doorway", TOBJ + "/door2");

    SetInventory(([ 
	TOBJ + "/staircase3" : 1,
	TNPC + "/rat" : 3,
      ]));

}
