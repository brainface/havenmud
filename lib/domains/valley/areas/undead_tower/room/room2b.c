//*       Created by Severen        *//
//*            room2b.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("inside a closet");
    SetLong(
      "This is the closet of the middle chamber inside the tower. "
      "There is a small shelf in here but nothing in them. The "
      "walls are made of stone and part of the wall has crumbled "
      "into a small pile of rubble. The opening in the north wall "
      "leads back into the chamber."
    );

    SetItems(([
	({"closet","room","tower"}) :
	(: GetLong :),
	({"north wall"}) :
	"An opening is here leading back into the middle chamber.",
	({"walls","wall"}) :
	"Like the rest of the tower, it is grey stone.",
	({"chamber"}) :
	"A better view of the chamber is available to the "
	"north.",
	({"shelf"}) :
	"The shelf is made of stone and is rather small. There "
	"is nothing in them right now.",
	({"east wall"}) :
	"The stone wall holds a door leading out of the room.",
	({"stone"}) :
	"Drab, grey stone much like the rest of the tower.",
	({"rubble","pile"}) :
	"A small pile of rubble where the wall has crumbled.",
	({"opening"}) :
	"On the north wall, an opening leads to another room.",
	({"floor"}) :
	"The floor does not have any dust on it and it relatively clean.",
      ]));

    SetItemAdjectives(([
	"chamber" : ({"middle","spotless"}),
	"floor" : ({"stone"}),
	"stone" : ({"grey"}),
	"rubble" : ({"small","pile","of"}),
	"closet" : ({"small"}),
	"shelf" : ({"small","stone"}),
	"wall" : ({"crumbled","grey","stone"}),
      ]));

    SetExits(([
	"north" : TROOM + "/room2a",
      ]));

}
