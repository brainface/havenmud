//*       Created by Severen        *//
//*            room1c.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("inside the lower chambers");
    SetLong(
      "This is the northern side of the lower chamber. Blood covers "
      "the walls and there are claw marks on them as well. A pile of "
      "bones rest in the corner and a large pentagram is drawn onto "
      "the floor. The ceiling hangs low in the room slopes upwards "
      "towards the south."
    );

    SetItems(([
	({"side","chamber","room"}) :
	(: GetLong :),
	({"blood"}) :
	"Thick red blood looks as if its dripping down the walls "
	"from a recent bloodbath.",
	({"walls","wall"}) :
	"Square walls with blood and claw marks scratched into them.",
	({"marks","mark"}) :
	"The hopeless attempt of some unfortunate person trying to "
	"get away from a beast. Or are they the claws of the beast?",
	({"pile","bones","bone"}) :
	"An adventurer at peace.",
	({"corner"}) :
	"In the northwest corner of the room there is a pile of "
	"bones.",
	({"pentagram"}) :
	"A five pointed star with a circle around it drawn onto the "
	"floor, it is drawn in blood.",
	({"floor"}) :
	"The floor of the room is made of stone. There is a pentagram "
	"drawn on it.",
	({"stone"}) :
	"The material used to build this whole tower.",
	({"ceiling"}) :
	"It is lower than in the room to the south and is lightly "
	"splattered with blood.",
      ]));

    SetItemAdjectives(([
	"chamber" : ({"northern","lower"}),
	"blood" : ({"thick","red","dripping"}),
	"walls" : ({"square","bloody","scratched","grey"}),
	"marks" : ({"claw"}),
	"bones" : ({"pile","of"}),
	"corner" : ({"northwest"}),
	"pentagram" : ({"large","bloody"}),
	"floor" : ({"stone"}),
	"ceiling" : ({"lower","lowered","lightly","splattered"}),
      ]));

    SetListen("default","A wailing can be heard here.");
    SetInventory (([
	TNPC + "/vampire" : 1,
	TOBJ + "/candles" : 1,
      ]));

    SetExits(([
	"south" : TROOM + "/room1b",
      ]));

}
