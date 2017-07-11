/*    /realms/haun/areas/mines/rooms/start2wsw.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a dark path end");
    SetDomain("Crystal Reaches");
    SetLong("Here it appears the path has suddenly ended; it doesn't seem"
      " to continue in any direction.  The forest surrounds the path, and"
      " the only entrance that is visible is from the small, hidden"
      " path that leads to the northeast.  Tall trees stand all around"
      " this area, partially blocking out the sky, leaving the area"
      " with little light.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"paths"  :  (: GetLong :),
	({"forest", "woods", "forests"}) :
	"The forest surrounds the path on all sides.  It seems very dark, and some"
	"what spooky.",
	({"entrance"})  :
	"The entrance leads back to the northeast.",
	({"tree", "trees"})  :
	"Trees stand tall into the sky, blocking out the majority of the light"
	" that plants need in this area to survive.  Most of them have large, broad"
	" leaves, that vary in color from green to brown.",

      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"dark", "small", "single"}),
	"paths"    :  ({"small", "dark"}),
	"forest"  :  ({"large", "dark"}),
	"entrance"    :  ({"northeastern"}),
	"tree"    :  ({"tall", "large"}),
      ]) );
    SetInventory( ([
	M1_NPC + "/raven1.c"  :  1,
      ]) ); 

    SetSmell( ([
	"default"  :  "The smell of fresh air lingers.",
      ]) );

    SetListen( ([
	"default"  :  "The sound of wildlife fills the air around the forest.",
      ]) );

    SetExits( ([
	"northeast"  :  M1_ROOM + "/start2w.c",
      ]) );
}
