//*       Created by Severen        *//
//*            stair7.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("on an upper staircase");
    SetLong(
      "This is an upper level of the staircase. Doors can be seen "
      "both above and below. Monotonous grey walls make up the "
      "majority of the scenery inside the tower and there are "
      "no windows or decorations found on them. It is a long "
      "drop to the floor far below. A pile of bones lie on the "
      "steps here."
    );

    SetItems(([
	({"level","tower","scenery"}) :
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
	"There are wooden doors both higher and lower on the staircase.",
	({"drop","floor"}) :
	"Way down there is the bottom of the tower.",
	({"bottom"}) :
	"It is a long drop to the floor from here.",
	({"bone","bones"}) :
	"The remains of some unlucky adventurer.",
      ]));

    SetItemAdjectives(([
	"level" : ({"upper"}),
	"walls" : ({"dull","grey","monotonous"}),
	"doors" : ({"wooden","above","below"}),
	"steps" : ({"worn","badly"}),
	"floor" : ({"bottom"}),
	"bones" : ({"pile","of"}),
	"drop" : ({"long"}),
      ]));

    SetInventory(([
	TOBJ + "/staircase7" : 1,
	TNPC + "/rat" : 3,
      ]));

}
