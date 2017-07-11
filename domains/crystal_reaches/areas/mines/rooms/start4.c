/*    /realms/haun/areas/mines/rooms/start4.c
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
    SetLong("Here the path turns sharply to the northwest.  The mountains lie"
      " directly south of this path. On the eastern side, there is a huge"
      " pile of boulders that have fallen from the cliff of a"
      " mountain that lies directly above.  The only exits are to the"
      " north, and to the northwest, which are both segments of the"
      " main path.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"paths"  :  (: GetLong :),
	({"mountain", "mountains", "cliff"}) :
	"There are huge mountains located directly to the south of this path."
	" They originate in the northeast, and continue until they end here.  The"
	" mountains have a green and brown color to them, because of the trees, and"
	" plants that cover them.",
	({"boulder", "boulders", "rock", "rocks", "pile"})  :
	"There are several huge boulders located to the eastern side of the path."
	" These rocks have a brown color, and appear to have fallen from the"
        " mountains above.",
	({"trees", "tree", "plants", "plant"})  :
	"Many varieties of trees and plants cover the mountain.  They are mostly"
	" of a green and brown color.",

      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"wide", "blocked", "dusty"}),
	"paths"    :  ({"wide", "blocked", "dusty"}),
	"boulder"  :  ({"huge", "brown"}),
	"rock"    :  ({"huge", "brown"}),
	"rocks"    :  ({"huge", "brown"}),
	"mountain"    :  ({"northern", "huge"}),
	"plants"    :  ({"brown", "green"}),
	"plant"    :  ({"green", "brown"}),
	"trees"    :  ({"brown", "green", "tall"}),
      ]) );

    SetInventory( ([M1_NPC + "/mgoat"  :  1,
	M1_NPC + "/fgoat"  :  2]) ); 
    SetSmell( ([
	"default"  :  "The smell of wildlife is present. ",
      ]) );

    SetListen( ([
	"default"  :  "The sound of falling rock is heard.",
      ]) );

    SetExits( ([
	"north"  :  M1_ROOM + "/start3.c",
	"northwest"  :  M1_ROOM + "/start4nw.c",
      ]) );
}
