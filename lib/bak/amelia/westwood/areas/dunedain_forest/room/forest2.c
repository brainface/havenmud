#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("a fork in the woods");
    SetLong("As the path continues to wind through the woods, it splits in "
      "two directions.  To the east, a road can be seen in the "
      "distance.  To the northwest and southwest, the path continues "
      "through the forest.  The forest thins out further to the west "
      "and the snowcapped peaks of mountain can be seen rising above "
      "the trees.");
    SetSmell( ([  "default" : "The smell of greenery is strong."]) );
    SetListen( ([ "default" : "A light wind causes the branches to rustle."]) );
    SetItems( ([
	({ "winding path","forest path","small path",
	  "fork in the woods","fork","roughly-made path","path" }) :
	(: GetLong() :),
	({ "eastern road","distant road","road" }) :
	"A road running north and south can barely be made out to "
	"the east.",
	({ "dense forest","dense trees","trees","tree","forest" }) :
	"To all sides, a number of trees are crowded together in "
	"a very dense forest.",
	({ "snowcapped peaks","mountain range","peaks","mountains" }) :
	"A mountain range can be made out to the west of the "
	"forest."
      ]) );
    SetInventory( ([
	//                 "/std/npc/a-h/deer" : 1,
	F_NPC "owl" : 2,
      ]) );
    SetObviousExits("northwest, southwest, east");
    SetExits( ([
	"east"      : F_ROOM "forest1",
	"northwest" : F_ROOM "forest3",
	"southwest" : F_ROOM "forest6",
      ]) );

}


/* Approved by Balishae on Thu Sep 11 14:16:26 1997. */
