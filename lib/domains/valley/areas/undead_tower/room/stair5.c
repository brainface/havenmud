//*       Created by Severen        *//
//*            stair5.c             *//
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
      "This is the central level of the staircase. The walls are a "
      "dull grey color and there are no windows or decorations upon "
      "them. Far below is the bottom floor of the tower and far above "
      "is the top of the tower. The steps are almost worn smooth from "
      "the centuries of wear and tear. On the staircase above and below, "
      "there are doors leading to other parts of the tower."
    );

    SetItems(([
	({"level","tower"}) :
	(: GetLong :),
	({"walls","wall"}) :
	"The walls are made of stone and are grey in color. There are "
	"no decorations or windows on them.",
	({"color"}) :
	"It is a dull, monotonous grey.",
	({"floor"}) :
	"It is a long drop to the floor below.",
	({"top"}) :
	"High above is the top of the tower. It looks as if it might fall "
	"sometime soon.",
	({"steps","step","stairs","stair"}) :
	"The stairs lead both up and down. They look worn from the ages of "
	"wear and tear.",
	({"doors","door"}) :
	"There are wooden doors both higher and lower on the staircase.",
      ]));

    SetItemAdjectives(([
	"level" : ({"central"}),
	"walls" : ({"dull","grey","stone"}),
	"doors" : ({"wooden","higher","lower"}),
	"steps" : ({"worn"}),
	"floor" : ({"bottom"}),
	"color" : ({"dull","grey","monotonous"}),
      ]));

    SetInventory(([
	TOBJ + "/staircase5" : 1,
	TNPC + "/sprite" : 4,
      ]));

}

