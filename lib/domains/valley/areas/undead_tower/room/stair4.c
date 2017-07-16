//*       Created by Severen        *//
//*            stair4.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("on the middle staircase");
    SetLong(
      "This is the middle of the staircase in the dark tower. Higher "
      "and lower on the staircase are doors that lead to other parts "
      "of the tower. The steps are cracked and parts of it are worn "
      "smooth, bringing to mind the distance to the bottom floor if one "
      "should fall. The stone walls have visible cracks and there are "
      "no windows or decorations on them."
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
	"A decent drop to the bottom floor. Jumping is out of the question.",
	({"drop"}) :
	"It is a long way down to the floor of the tower.",
	({"below"}) :
	"The rest of the staircase going down.",
	({"top"}) :
	"The top of the staircase is a winding climb.",
	({"distance"}) :
	"It is a long way down to the bottom of the tower.",
	({"doors","door"}) :
	"There are doors above and below.",
	({"steps","step","stairs"}) :
	"A magnificent work of craftsmanship, the staircase looks as if "
	"it was carved out of the walls themselves. It does look very old "
	"and caution should be used climbing it. There is a door higher "
	"up and further down the staircase.",
	({"middle"}) :
	"This is the middle part of the staircase.",
	({"cracks","crack"}) :
	"Due to the age of the tower, cracks have formed on its walls and "
	"stairs.",
      ]));

    SetItemAdjectives(([
	"tower" : ({"dark"}),
	"walls" : ({"stone","cracked","grey"}),
	"stone" : ({"dull","grey"}),
	"stairs" : ({"magnificent","old","grey","spiraling","carved",
	  "badly","worn","cracked"}),
	"floor" : ({"bottom"}),
	"distance" : ({"long"}),
      ]));

    SetListen("default","The faint sound of footsteps can be heard.");

    SetInventory(([
	TOBJ + "/staircase4" : 1,
	TNPC + "/beetle" : 3,
      ]));

}
