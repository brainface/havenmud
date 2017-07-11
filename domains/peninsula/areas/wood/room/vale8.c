/* 5/03 Libitina / newbie area / wooded vale */

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "Tall corsican pine trees spread their branches, creating a "
      "quiet canopy of dancing light. Sunrays dart down in graceful lines "
      "towards the narrow trail. The forest gets more dense to the north, "	
      "and the trail heads either south or east from here. Thick underbrush "
      "grows at the foot of the trees, covered in small flowers and "
      "ripe berries."
    );
    SetItems( ([
	({"trees", "branches"}) : "These tall trees are thick with branches.",
	"canopy" : "Branches mesh together creating a nice world of life.",
	"trail" : "From here you can go north, south, or east.",
	({ "underbrush", "flowers", "berries" }) : "Several plants grow "
	"here, sprouting small white flowers, and various kinds "
	"of berries."
      ]) );
    SetSmell("default", 
      "The scent of fresh pine fills the air."
    );
    SetListen("default", 
      "The hushed sounds of forest life can be heard."
    );
    SetExits( ([
	"north" : WOOD_ROOM "vale9.c",
	"east" : WOOD_ROOM "vale7.c",
	"south" : WOOD_ROOM "vale1.c"
      ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
