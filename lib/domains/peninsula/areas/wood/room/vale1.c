/*  5/03 Libitina  / newbie area / wooded vale  */

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "The path curves eastward here, with a small gametrail leading "
      "to the northeast. Several trees reach towards the sky, drinking "
      "in the sun and creating a nice canopy. Light dances through the "
      "branches, illuminating the area just enough for dense underbrush "
      "to grow."
    );
    SetItems( ([
	"path" : "Tendrils of shrubbery reach across the path, looking for "
	"more room to expand. Pine needles from the trees create "
	"a scented carpet to tread on.",
	"gametrail" : "A smaller path leads northeast, created by small forest "
	"creatures, certainly not a path for large beasts.",
	"trees" : "Corsican pine trees dominate this small forest.",
	({"canopy", "light", "branches"}) : "The corsican pine trees reach "
	"their "
	"branches towards each other, "
	"allowing only thin beams of sunlight through.",
	"underbrush" : "Several plants make their home at the base of "
	"the trees. "
      ]) );
    SetSmell("default", 
      "The scent of pine needles is strong."
    );
    SetListen("default", 
      "Something chitters in the distance."
    );
    SetInventory( ([
        WOOD_NPC + "bird" : 1,
    ]) );
    SetExits( ([
	"south" : WOOD_ROOM "entrance.c",
	"northeast" : WOOD_ROOM "vale7.c",
	"north" : WOOD_ROOM "vale8.c",
	"east" : WOOD_ROOM "vale2.c"
      ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
