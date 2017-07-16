/*    /realms/haun/areas/mines/rooms/start2w.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a small forest path");
    SetDomain("Crystal Reaches");
    SetLong("This small path runs through a little forest that overtakes"
      " the land in the area.  Brush, trees and foliage are located on all"
      " sides of the path which makes it hard to distinguish the"
      " direction that leads to safety.  There appears to be a"
      " larger path to the east, and this path seems to continue"
      " in a southwesternly direction.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"paths"  :  (: GetLong :),
	({"brush", "tree", "trees", "foliage"}) :
	"Brush, trees and foliage surround the path on all sides.  Most"
	" of this growth, is in the form of small plants, but there are a" 
	" few larger ones present.",
      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"small", "forest"}),
	"paths"    :  ({"small", "forest"}),
	"tree"    :  ({"large", "small"}),
      ]) );
    SetSmell( ([
	"default"  :  "The smell of fresh plants are present in the air",
      ]) );

    SetListen( ([
	"default"  :  "The sound of wildlife is heard.",
      ]) );

    SetExits( ([
	"east"  :  M1_ROOM + "/start2.c",
	"southwest"  :  M1_ROOM + "/start2wsw.c",
      ]) );
}
