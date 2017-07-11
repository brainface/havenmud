//*       Created by Severen        *//
//*            stair8.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("the top of the staircase");
    SetLong(
      "This is the topmost level of the staircase. There is a door"
      "way here with a door in it leading to another part of the tower. "
      "Far below is the bottom floor of the tower and the rest of the stair"
      "case spirals all the way to it. Further down the staircase are "
      "other doors. The ceiling of the tower is right above and "
      "tapers to a point."
    );

    SetItems(([
	({"level","tower"}) :
	(: GetLong :),
	({"walls","wall"}) :
	"The walls are made of stone and are grey in color. There are "
	"no decorations or windows on them.",
	({"floor"}) :
	"It is a long drop to the floor below.",
	({"steps","step","stairs","stair"}) :
	"The stairs lead both up and down. They look worn from the ages of "
	"wear and tear.",
	({"doors"}) :
	"There are wooden doors below on the staircase.",
	({"drop","floor"}) :
	"Way down there is the bottom of the tower.",
	({"point"}) :
	"The very top of the tower.",
	({"taper"}) :
	"The gradual sloping of the ceiling. It comes to a point.",
	({"bottom"}) :
	"It is a long drop to the floor from here.",
	({"ceiling"}) :
	"The ceiling is just above and tapers to a point. It is "
	"grey stone as the rest of the tower is.",
	({"doorway"}) :
	"A doorway stands here leading into another part of the "
	"tower.",
      ]));

    SetItemAdjectives(([
	"level" : ({"topmost"}),
	"walls" : ({"dull","grey","monotonous"}),
	"doors" : ({"wooden","above","below"}),
	"steps" : ({"worn","torn"}),
	"floor" : ({"bottom","long"}),
	"ceiling" : ({"tapered","above"}),
      ]));

    SetObviousExits("doorway");

    SetEnters(([
	"doorway" : TROOM "/room3",
      ]));

    SetDoor("doorway", TOBJ + "/door4");

    SetInventory(([
	TOBJ + "/staircase8" : 1,
	TNPC + "/rat" : 3,
      ]));

}
