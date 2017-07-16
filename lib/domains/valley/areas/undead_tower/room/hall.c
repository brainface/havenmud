//*       Created by Severen        *//
//*             hall.c              *//
//*       Mid November 1998         *//

// mahkefel, july 5th 2010: made sprites in this room not climb
// up and down. ridiculous numbers of sprites were accumulating
// in this room.
#include <lib.h>
#include <climb.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("the hall of an ancient tower");
    SetLong(
      "Inside of a strange dark hall of the ancient tower, dust covers "
      "the floor with a chaotic collage of small tracks. The walls are "
      "circular and made of stone and there are no windows visible. The "
      "bottom of a magnificent staircase rests here providing a way to "
      "the top of the tower, it seems to be carved out of the walls "
      "themselves. Other than the staircase, there are no decorations on "
      "the walls. There is an opening in the south wall."
    );

    SetItems(([
	({"tower","hall","room"}) :
	(: GetLong :),
	({"walls","wall"}) :
	"They form a circular room and are made of the same grey stone that "
	"the outside of the tower is made of.",
	({"stone"}) :
	"Grey stone that looks like it would crumble at the touch.",
	({"opening"}) :
	"There is no door in this opening and it leads to a smaller room "
	"within the tower.",
	({"dust"}) :
	"Thick dust from the ages of never being cleaned. Tracks litter "
	"the floor in every direction.",
	({"south wall"}) :
	"An opening is located along this wall.",
	({"floor"}) :
	"It is covered with dust and tracks.",
	({"tracks","track"}) :
	"Taking a closer look at the tracks, they seem to be mice "
	"tracks. There are cat tracks as well.",
	({"mice tracks","mice track"}) :
	"They look like mice tracks.",
	({"cat tracks","cat track"}) :
	"They look like cat tracks.",
	({"collage"}) :
	"Tracks, tracks, they're everywhere!",
	({"bottom"}) :
	"It is the bottom of the staircase climbing up to the top.",
	({"top"}) :
	"The top of the tower is shrouded in darkness.",
	({"door"}) :
	"A door is visible up the staircase.",
      ]));

    SetItemAdjectives(([
	"tower" : ({"ancient","old","dull"}),
	"hall" : ({"strange","dark"}),
	"walls" : ({"dull","grey","stone","circular","grey"}),
	"stone" : ({"dull","grey"}),
	"dust" : ({"thick","layer","of"}),
	"tracks" : ({"small"}),
	"collage" : ({"chaotic"}),
	"floor" : ({"dusty","tracked"}),
      ]));

    SetSmell((["room" : "It smells dusty in here."]));
    SetListen("default","The faint sound of footsteps can "
      "be heard here.");

    SetExits(([
	"south" : TROOM + "/foyer",
      ]));

    SetInventory(([
	TOBJ + "/hallcase" : 1,
TNPC + "/sprite_noclimb" : 3,
      ]));

}
