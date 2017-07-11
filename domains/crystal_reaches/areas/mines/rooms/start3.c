/*    /realms/haun/areas/mines/rooms/start3.c
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
    SetLong("Here the path waves slowly southward, as it gets deeper into the"
      " mountains.  The path becomes a little wider here, and a forest is"
      " located on the western side of the path.  The mountains start"
      " on the eastern side, then curve around, so that they are visible"
      " to the south of here. This path continues to the south, and goes"
      " back up to the northwest.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"paths"  :  (: GetLong :),
	({"mountains", "mountain", "range", "curve", "east"}) :
	"This large mountain range lies to the east and to the north.  The mountains"
	" contained in it are covered with trees and small brush, giving them"
	" a green and brown color.",
	({"forest", "west"})  :
	"A forest lies to the west of this path.  This forest consists mainly of"
	" large trees which tower high into the sky.  It provides this path"
	" some shade during the day.",
	({"tree", "trees"})  :
	"The trees are multi colored, which mainly consist of brown and green hues."
	"  They fill the forest, and tower high in the sky.",
      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"wide", "large", "dusty"}),
	"paths"    :  ({"wide", "large", "dusty"}),
	"mountains"  :  ({"green", "brown", "large"}),
	"forest"    :  ({"large"}),
	"tree"  :  ({"colored", "brown", "green", "high"}),
	"curve"    :  ({"mountain"}),

      ]) ); 

    SetSmell( ([
	"default"  :  "The smell of fresh plant growth fills the air.",
      ]) );

    SetListen( ([
	"default"  :  "The sound of wildlife can be heard.",
      ]) );

    SetExits( ([
	"northwest"  :  M1_ROOM + "/start2.c",
	"south"  :  M1_ROOM + "/start4.c",
      ]) );
}
