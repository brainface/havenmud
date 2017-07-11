//*       Created by Severen        *//
//*            stair2.c             *//
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
      "This is a lower part of the staircase. The steps are badly worn with "
      "the ages of use and improper care. Grey walls with no decorations "
      "or windows give the setting an eerie tone. There is a door further "
      "up the stairs and an opening in the south wall of the room below is "
      "visible."
    );

    SetItems(([
	({"tower","room"}) :
	(: GetLong :),
	({"room below"}) :
	"Below is the hall of the tower. It looks like a long "
	"drop from here.",
	({"walls","wall"}) :
	"They form a circular room and are made of the same grey stone that "
	"the outside of the tower is made of. A staircase spirals up and "
	"down it.",
	({"stone"}) :
	"Grey stone that looks like it would crumble at the touch.",
	({"opening"}) :
	"On the south wall of the room below stands a doorless opening to "
	"another room within the tower.",
	({"dust"}) :
	"It is hard to discern exactly what is on the floor down there "
	"from this height on the stairs.",
	({"floor"}) :
	"A decent drop to the bottom floor. Jumping is out of the question.",
	({"setting"}) :
	"The single color of everything and the strange silence would send "
	"a chill up anyone's spine.",
	({"below"}) :
	"The rest of the staircase going down",
	({"top"}) :
	"The top of the staircase is a winding climb.",
	({"part"}) :
	"This is the lower part of the staircase.",
	({"door"}) :
	"A door is visible up the staircase.",
	({"south wall"}) :
	"There is an opening located on it.",
	({"steps","stairs"}) :
	"The steps spiral both up and down from here. They are "
	"worn from the ages of use and lack of maintenance.",
      ]));

    SetItemAdjectives(([
	"tower" : ({"ancient","old","dull"}),
	"walls" : ({"dull","grey","stone","circular"}),
	"stone" : ({"dull","grey"}),
	"dust" : ({"thick","layer","of"}),
	"stairs" : ({"magnificent","old","grey","spiraling","carved",
	  "badly","worn"}),
	"floor" : ({"bottom"}),
	"part" : ({"lower"}),
	"opening" : ({"doorless"}),
	"setting" : ({"eerie","monotone"}),
      ]));

    SetSmell("default","The fragrance of death and decay fills "
      "the nostrils.");

    SetInventory(([ 
	TOBJ + "/staircase2" : 1,
	TNPC + "/cat" : 3,
      ]));

}
