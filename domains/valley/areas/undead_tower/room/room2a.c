//*       Created by Severen        *//
//*            room2a.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("inside the middle chamber");
    SetLong(
      "Inside the middle chamber, this looks to have belonged to a "
      "powerful wizard due to its decorations. It is virtually spotless and "
      "there is no dust on the floor. A table rests along the north "
      "wall and there is a opening to a closet on the south wall. "
      "Next to the table is a bed. A large tapestry hangs on the west "
      "wall and there is a door leading out of the room to the east."
    );

    SetItems(([
	({"side","chamber","room"}) :
	(: GetLong :),
	({"decorations"}) :
	"A tapestry hangs on the wall and furniture decorates the room.",
	({"north wall","wall"}) :
	"It is made of grey stone and there is a table resting there.",
	({"walls","wall"}) :
"The walls are grey stone and each have some characteristics about them.",
	({"south wall","wall"}) :
	"It is made of stone and there is an opening here to what looks "
	"like a closet.",
	({"west wall","wall"}) :
	"A large tapestry hangs here covering most of the stone wall.",
	({"east wall","wall"}) :
	"The stone wall holds a door leading out of the room.",
	({"opening"}) :
	"An opening is here leading to a small closet. It is not very large.",
	({"closet"}) :
	"A better view of the closet can be seen from within.",
	({"tapestry"}) :
	"The tapestry shows a grand design of what wizardry was like "
	"in the past. Parts of it show a battle between two wizards and "
	"shows its lively display of pyrotechnics and icy spells. The "
	"rest of the tapestry shows archaic symbols, magical designs, "
	"mystical schematics of arcane rituals. Definately the pride "
	"of its owner.",
	({"battle"}) :
	"A viscious battle between two wizards fighting with their powerful "
	"spells. The spells seem to be one of an ice storm and the other "
	"of a gigantic firestorm.",
	({"wizard","wizards"}) :
	"One seems to be very young and the other seems to be very old. "
	"They are both wearing the same black robes with silver fringe.",
	({"display"}) :
	"The show of power is evident by both wizards of the tapestry.",
	({"archaic symbol","archaic symbols","symbols","symbol"}) :
	"Whispy designs of a runic nature. One is a circle with eight "
	"arrows pointing in each compass direction. Another is a slash "
	"with two more slashes through it. There are many of these types "
	"of symbols on the tapestry.",
	({"magical design","magical designs","design","designs"}) :
	"Sketches of dragons and fairies and all sorts of magical beings.",
	({"mystical schematics","mystical schematic","schematic","schematics"}) :
	"Numbers and marks noting the precise things for some ritual.",
	({"dust"}) :
	"There is no dust here.",
	({"stone"}) :
	"The material used to build this whole tower. It is grey.",
	({"floor"}) :
	"The floor does not have any dust on it and it is relatively clean.",
      ]));

    SetItemAdjectives(([
	"chamber" : ({"middle","spotless"}),
	"floor" : ({"stone","clean"}),
	"stone" : ({"grey"}),
	"tapestry" : ({"large","grand"}),
      ]));

    SetObviousExits("south, out");

    SetExits(([
	"south" : TROOM + "/room2b",
	"out" : TROOM + "/stair6",
      ]));

    SetDoor("out", TOBJ + "/door3");

    SetInventory(([
	TOBJ + "/table" : 1,
	TOBJ + "/bed" : 1,
	TNPC + "/wight" : 1,
      ]));

}
