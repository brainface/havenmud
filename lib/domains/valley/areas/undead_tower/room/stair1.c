//*       Created by Severen        *//
//*            stair1.c             *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(5);

    SetShort("on a lower staircase");
    SetLong(
      "This is the lower end of the staircase. It spirals up the tower "
      "to its very top. A door is visible up the staircase and there is "
      "an opening in the south wall of the room below. The walls have no "
      "decorations or markings and there are no windows on them. The floor "
      "of the room below is noticeably covered with tracks in its dust."
    );

    SetItems(([
	({"room below"}) :
	"Down the stairs is the bottom floor of the tower. Dust covers "
	"its floors and is covered with tracks. An exit leads south in that room.",
	({"tower","hall"}) :
	(: GetLong :),
	({"walls","wall"}) :
	"They form a circular room and are made of the same grey stone that "
	"the outside of the tower is made of. A staircase spirals up it.",
	({"stone"}) :
	"Grey stone that looks like it would crumble at the touch.",
	({"opening"}) :
	"On the south wall of the room below stands a doorless opening to "
	"another room within the tower.",
	({"dust"}) :
	"Thick dust from the ages of never being cleaned. Tracks litter "
	"the floor in every direction.",
	({"floor"}) :
	"It is covered with dust and tracks.",
	({"tracks","track"}) :
	"Maybe a closer look will reveal their nature.",
	({"bottom"}) :
	"It is the bottom of the staircase climbing up to the top.",
	({"top"}) :
	"The top of the staircase is a winding climb.",
	({"end"}) :
	"This is the lower end of the staircase.",
	({"door"}) :
	"A door is visible up the staircase.",
	({"south wall"}) :
	"There is an opening located on it.",
	({"stairs","steps"}) :
	"A magnificent work of craftsmanship, the staircase looks as if "
	"it was carved out of the walls themselves. It look very old "
	"and caution should be used climbing it. Noticeable is a door higher "
	"up the staircase.",
      ]));

    SetItemAdjectives(([
	"tower" : ({"ancient","old","dull","strange","dark"}),
	"walls" : ({"dull","grey","stone","circular"}),
	"stone" : ({"dull","grey"}),
	"dust" : ({"thick","layer","of"}),
	"tracks" : ({"small"}),
	"stairs" : ({"magnificent","old","grey","spiraling","carved"}),
	"floor" : ({"noticeably","covered","littered"}),
	"end" : ({"lower"}),
	"opening" : ({"doorless"}),
      ]));

    SetSmell("default","The fragrance of death and decay fills "
      "the nostrils.");

    SetInventory(([
	TOBJ + "/staircase1" : 1,
	TNPC + "/rat" : 3,
      ]));

}
