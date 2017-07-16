//*       Created by Severen        *//
//*            foyer.c              *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("inside an ancient tower");
    SetLong(
      "This is a small room within the ancient tower. A table stands "
      "on the west wall and a door stands to the south as a means of "
      "exiting the tower. The walls here are a dull grey stone and "
      "there are no decorations on it. An opening to the north leads "
      "into another room within this structure. A thick layer of dust "
      "is on the floor with small tracks leading all about."
    );

    SetItems(([
	({"tower","room"}) :
	(: GetLong :),
	({"walls","wall"}) :
	"Being a small room, they are close together and made of a dull, "
	"grey stone. There is nothing peculiar about them.",
	({"stone"}) :
	"Much like the same stone that the outside of the tower is made "
	"of, it looks like it would crumble at the touch.",
	({"west wall"}) :
	"A table is there.",
	({"opening"}) :
	"There is no door in this opening and it leads to a larger room "
	"within the tower.",
	({"dust"}) :
	"Thick dust from ages of never being cleaned. There are small "
	"tracks in it.",
	({"tracks","track"}) :
	"Taking a closer look at the tracks, they seem to be mice tracks. "
	"There are also some cat tracks.",
	({"mice tracks","mice track"}) :
	"They look like mice tracks.",
	({"cat tracks","cat track"}) :
	"They look like cat tracks.",
      ]));

    SetItemAdjectives(([
	"tower" : ({"ancient","old","dull","small","dusty"}),
	"walls" : ({"dull","grey","stone"}),
	"stone" : ({"dull","grey"}),
	"dust" : ({"thick","layer","of"}),
	"tracks" : ({"small","mice","cat"}),
      ]));

    SetSmell("room","It smells dusty in here.");

    SetExits(([
	"out" : TROOM + "/entrance",
	"north" : TROOM + "/hall",
      ]));

    SetDoor("out", TOBJ + "/door1");

    SetInventory(([ 
	TOBJ + "/table" : 1,
      ]));

}
