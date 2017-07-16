/*    /realms/haun/areas/mines/rooms/start2e.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a mountain path");

    SetDomain("Crystal Reaches");
    SetLong("After entering this small path, it is hard to not notice the"
      " large mountain range that lies east of this point.  This path is"
      " mostly barren, but contains some small brush, which cover"
      " the ground around the path.  There are rocks lying all around,"
      " some even large boulders.  This path seems to end here, because"
      " the mountains make further passage impossible.  Back to"
      " the west, is a larger path for which is the only exit.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"paths"  :  (: GetLong :),
	({"mountain", "mountains", "range"}) :
	"There is a huge mountain range that lies to the east.  This mountain"
	" range is not long in length, but it does contain many high mountains.  The"
        " mountains appear to be full of trees and vegetation, making them inherit a"
	" greenish, brown color.",
	({"brush", "plants", "plant", "vegetation", "trees"})  :
	"The appearance of these plants consist of green and brown hues.  They are"
	" located all around this path and on the sides of the mountains.",
	({"ground", "floor"})  :
	"The ground here is a dark brown color and is littered with brush and"
        " rocks.",
	({"rocks", "boulder", "boulders"})  :
	"These large, brown rocks litter the ground around this path.",
      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"mountain", "small", "rocky"}),
	"paths"    :  ({"mountain", "small", "rocky"}),
	"mountain"  :  ({"large", "tall"}),
	"range"    :  ({"large", "small"}),
	"brush"    :  ({"thick", "scattered"}),
	"plants"    :  ({"scattered", "thick"}),
	"ground"    :  ({"littered", "rocky"}),
	"rocks"    :  ({"large", "round"}),
	"boulders"    :  ({"large"}),
      ]) );
    SetInventory( ([
	M1_NPC + "/cougar"  :  1
      ]) ); 

    SetSmell( ([
	"default"  :  "The smell of fresh air lingers.",
      ]) );

    SetListen( ([
	"default"  :  "The sound of wildlife is heard abundantly.",
      ]) );

    SetExits( ([
	"west"  :  M1_ROOM + "/start2.c",
      ]) );
}
