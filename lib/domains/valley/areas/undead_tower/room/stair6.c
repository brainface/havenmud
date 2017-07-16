//*       Created by Severen        *//
//*            stair6.c             *//
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
      "This is the central level of the staircase. There is a doorway "
      "here and looking above and below, more doors can be seen. The "
      "walls are bare and grey and no decorations or windows may be "
      "found on them. Far below is the floor to the tower which brings "
      "to mind the poor shape the steps are in."
    );

    SetItems(([
	({"level","tower"}) :
	(: GetLong :),
	({"walls","wall"}) :
	"The walls are made of stone and are grey in color. There are "
	"no decorations or windows on them.",
	({"floor"}) :
	"It is a long drop to the floor below.",
	({"top"}) :
	"High above is the top of the tower. It looks as if it might fall "
	"sometime soon.",
	({"steps","step","stairs","stair"}) :
	"The stairs lead both up and down. They look worn from the ages of "
	"wear and tear.",
	({"doors"}) :
	"There are wooden doors both higher and lower on the staircase.",
	({"doorway"}) :
	"There is a doorway here leading to another part of the tower. "
	"A door is set in it.",
      ]));

    SetItemAdjectives(([
	"level" : ({"central"}),
	"walls" : ({"dull","grey","bare","stone"}),
	"doors" : ({"wooden","higher","lower"}),
	"steps" : ({"worn","poor"}),
	"floor" : ({"bottom"}),
      ]));

    SetObviousExits("doorway");

    SetEnters(([
	"doorway" : TROOM + "/room2a",
      ]));

    SetDoor("doorway", TOBJ + "/door3");

    SetInventory(([
	TOBJ + "/staircase6" : 1,
	TNPC + "/cat" : 3,
      ]));

}

