//*       Created by Severen        *//
//*            room3.c              *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("inside the upper chamber");
    SetLong(
      "This is the upper chamber of the ancient tower. The room "
      "seems to be a mages laboratory. There is a large table "
      "in the center of the room and scattered upon it are notes "
      "and various tools of magic. A cabinet stands on the north "
      "wall and a large black circle is drawn onto the south wall. "
      "The walls have no other decorations upon it and there is a "
      "door leading out of the room on the east wall."
    );

    SetItems(([
	({"note","notes"}) :
	"Various notes upon which is written a language not understood.",
	({"tools"}) :
	"The tools on the table seem to be a part of the table. There "
	"is a strange stargazing device and an abacus. Also a strange "
	"rod sticks out of the table.",
	({"device"}) :
	"It is triangular and has a peephole in it. It seems "
	"to be made of stone.",
	({"abacus"}) :
	"A tool used for counting large numbers.",
	({"rod"}) :
	"A silver colored rod sticks from the table. Its use is unknown.",
	({"chamber","room","tower","laboratory"}) :
	(: GetLong :),
	({"north wall"}) :
	"It is made of stone and there is a cabinet here.",
	({"walls","wall"}) :
	"Like the rest of the tower, it is grey stone.",
	({"east wall"}) :
	"A door here leads out.",
	({"stone"}) :
	"Drab, grey stone much like the rest of the tower.",
	({"center"}) :
	"In the center of the room stands a table.",
	({"south wall"}) :
	"It is made of stone and there is a large black circle "
	"drawn onto it.",
	({"circle"}) :
	"A circle drawn onto the wall for some unknown reason. "
	"It seems to be drawn there with charcoal.",
	({"doorway"}) :
	"A door stands in the east wall. It leads out.",
      ]));

    SetItemAdjectives(([
	"rod" : ({"silver","colored"}),
	"device" : ({"strange","stargazing"}),
	"chamber" : ({"upper","mages","ancient"}),
	"floor" : ({"stone"}),
	"stone" : ({"grey"}),
	"circle" : ({"large","black"}),
	"shelf" : ({"small"}),
	"wall" : ({"crumbled","grey","stone"}),
      ]));

    SetObviousExits("out");

    SetExits(([ "out" : TROOM + "/stair8", ]));

       SetDoor("out", TOBJ + "/door4");

    SetInventory(([

	TOBJ + "/l_table" : 1,
	TOBJ + "/cabinet" : 1,
	TNPC + "/lich" : 1,
      ]));
}
