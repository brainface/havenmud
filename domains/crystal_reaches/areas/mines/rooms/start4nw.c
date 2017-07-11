/*    /realms/haun/areas/mines/rooms/start4nw.c
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
    SetLong("Here the path leads toward the west.  To the north, there is a"
      " small forest, which contains many large trees and small brush.  There"
      " are boulders to the east, that have fallen from the cliffs"
      " that are located high on the mountain above.  This path"
      " continues to the west, and to the southeast.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"paths"  :  (: GetLong :),
	({"forest", "forests"})  :
	"This small forest lies to the north of this path.  It contains many large"
	" trees and small brush which litter it with many hues of browns and green.",
	({"trees", "tree"})  :
	"These trees are quite large, and are very colorful with many hues of"
	" brown and green."  "They appear as towers in the sky, and contain"
	" wide, broad leaves.",
	({"boulders", "boulder", "rock"})  :
	"These huge, brown boulders litter the ground to the east.  The create"
	" a boundary, in which the path follows.  They appear to have fallen"
	" from the mountain above. ",
	({"cliff", "mountain", "mountains"})  :
	"This very high range of mountains are located to the south of the path."
	" The huge boulders appear to have fallen from here.",

      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"dusty", "littered"}),
	"paths"    :  ({"dusty", "littered"}),
	"forest"  :  ({"green", "brown", "small"}),
	"trees"    :  ({"tall", "brown", "green"}),
	"boulders"    :  ({"brown", "huge"}),
	"boulder"    :  ({"brown", "huge"}),
	"rocks"    :  ({"brown", "huge"}),
	"cliff"    :  ({"high", "rocky"}),
	"mountain"    :  ({"large", "brown", "high"}),
      ]) );

    SetSmell( ([
	"default"  :  "The smell of fresh growth is present.",
      ]) );

    SetListen( ([
	"default"  :  "The sound of nature is abundant.",
      ]) );

    SetExits( ([
	"west"  :  M1_ROOM + "/start4nww.c",
	"southeast"  :  M1_ROOM + "/start4.c",
      ]) );
}
