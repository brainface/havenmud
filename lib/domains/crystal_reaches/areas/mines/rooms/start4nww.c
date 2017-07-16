/*    /realms/haun/areas/mines/rooms/start4nww.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a dusty path end");
    SetDomain("Crystal Reaches");
    SetLong("This path ends here, at a completely dead end.  The high"
      " mountains are located on the southern end of the path, and"
      " the forest lies to the north.  Located on the mountain seems"
      " to be an overgrown mine.  The tunnel entrance is partially"
      " visible, where it has been overgrown be various vines and shrubs."
      " The only exits appear to be to the east, and down into the mine.");
    SetItems( ([
	"path"  :  (: GetLong :),
	"paths"  :  (: GetLong :),
	({"mountain", "mountains", "cliff", "cave", "tunnel", "mine"}) :
	"The mountains lie to the south.  There is a secluded tunnel that is located"
	" in the side of the mountain.  It appears to be used, but not often.",
	({"forest"})  :
	"  There is a small forest located to the north.  It contains many"
	" varieties of plants, included small shrubs, and large trees.",
	({"vines", "shrubs", "shrub"})  :
	"Vines and shrubs block the entrance to the cave, partially hiding it"
	" from public view.  They are composed of green and brown hues, making them"
	" blend in with their surroundings.",
	({"tree", "trees"})  :
	"These trees are located in or around the forest which lies to the north."
	"  They create a beautiful brown and green collage of colors.",

      ]) );

    SetItemAdjectives( ([
	"path"    :  ({"end", "large", "dusty"}),
	"paths"    :  ({"end", "large", "dusty"}),
	"mountain"  :  ({"large", "rocky"}),
	"forest"    :  ({"small"}),
	"vine"    :  ({"green", "brown"}),
	"tree"    :  ({"tall", "green", "brown"}),
	"mine"    :  ({"secluded", "hidden", "concealed", "wide"}),
	"shrub"    :  ({"green", "brown", "black", "entangled"}),
      ]) );

    SetInventory( ([
	M1_NPC + "/bear1.c"  :  1
      ]) ); 
    SetSmell( ([
	"default"  :  "The smell fresh air fills the area.",
      ]) );

    SetListen( ([
	"default"  :  "The sound of dripping water is heard.",
      ]) );

    SetExits( ([
	"down"  :  M1_ROOM + "/entrance.c",
	"east"  :  M1_ROOM + "/start4nw.c",
      ]) );

}
