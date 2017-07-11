/*    /realms/haun/areas/mines/rooms/start.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a dusty path");
    SetDomain("Crystal Reaches");
    SetLong("A small path, which runs to the south, begins here.  The path is"
      " guarded on both sides by small shrubs, and there is a huge tree which"
      " lies to the southeastern end of the path.  The healthy looking"
      " tree stands, rising high like a tower in the sky, to the surrounding"
      " lands.  This small path seems to wind in a southernly direction,"
      " and back to the north it intersects Glimmerdin Road.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"room"  :  (: GetLong :),
	({"shrub", "shrubs", "plant", "plants"}) :
	"These small shrubs line the sides of the path.  They are in no"
	" particular orientation, and seem to be randomly planted.",
	({"tree", "trees", "tower"})  :
	"To the southeast corner of the path a large, healthy tree stands"
	" high. It is green, and is fully of large, broad leaves.",
	({"road", "glimmerdin road"})  :
	"Glimmerdin Road lies to the north of this path.",
      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"small", "lined"}),
	"shrubs"    :  ({"unoriented", "small"}),
	"tree"  :  ({"towering", "huge"}),
	"tower"    :  ({"huge"}),
      ]) );


    SetSmell( ([
	"default"  :  "The smell fresh air surrounds the area.",
      ]) );

    SetListen( ([
	"default"  :  "The sounds of nature embellishes the area.",
      ]) );

    SetExits( ([
        "north"  :  "/domains/crystal_reaches/virtual/glimmerdinroad/-12,22",
	"south"  :  M1_ROOM + "/start2.c",
      ]) );
}
