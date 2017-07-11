//*       Created by Severen        *//
//*            room1b.c             *//
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
      "This is a lower chamber of the tower. It is a square room "
      "with no windows. The walls are covered in blood and have "
      "claw marks on them. There are bones scattered about everywhere "
      "and pieces of broken armour and weapons litter the room. There "
      "is a door here as a means for an exit from the room. The room "
      "extends to the north and south from here."
    );

    SetItems(([
	({"puddle","puddles"}) :
	"Puddles of blood collect near the walls edge.",
	({"chamber","tower","room"}) :
	(: GetLong :),
	({"wall","walls"}) :
	"Covered in blood and claw marks, it makes the room look ghastly.",
	({"blood"}) :
	"It still drips from the wall to puddles on the floor.",
	({"marks","mark","claw mark","claw marks"}) :
	"Claw marks on the wall suggest a struggle has occurred here.",
	({"bone","bones"}) :
	"Bones lie on the floor in piles and looks like it was "
	"something's dinner.",
	({"armour","weapon","pieces","weapons","piece"}) :
	"They rest near the bones of some unlucky adventurers and look "
	"worthless.",
	({"exit"}) :
	"An exit out of the room.",
	({"out"}) :
	"There is a door here leading out.",
      ]));

    SetItemAdjectives(([
	"chamber" : ({"lower","square","littered"}),
	"walls" : ({"square","blood","covered","claw"}),
	"armour" : ({"broken"}),
	"bones" : ({"scattered"}),
      ]));

    SetSmell("default","The smell of blood is extremely strong.");

    SetObviousExits("north, south, out");

    SetInventory (([
	TNPC + "/cat" : 3,
      ]));
    SetExits(([
	"north" : TROOM + "/room1c",
	"out" : TROOM + "/stair3",
	"south" : TROOM + "/room1a",
      ]));

    SetEnters(([
	"out" : TROOM + "/stair3",
      ]));

    SetDoor("out", TOBJ + "/door2");

}
