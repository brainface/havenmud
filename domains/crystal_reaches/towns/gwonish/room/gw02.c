#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("a meeting point of paths");
	SetExits( ([
	  "north" : GWONISH_ROOM "gw07",
	  "east"  : GWONISH_ROOM "gw04",
	  "west"  : GWONISH_ROOM "gw03",
	  "south" : GWONISH_ROOM "gw01",
	  ]) );
	SetLong(
	  "The swampy path, little more than a dry walkway through the "
	  "swamp, continues in four directions from here. To the north is "
	  "what appears to be the center of the village. To the south lies "
	  "the open sea, and to the east and west the path continues off through "
	  "the village. The dark trees hang over the path in a grisly manner "
	  "that seems to strangle the life from the swamp, while foul creatures "
	  "slither through the muck."
	  );
	SetItems( ([
	  ({ "creature", "creatures" }) : "More felt and heard than seen, these "
	     "beasts are the normal inhabitants of a murky swamp.",
	  ({ "tree", "trees" }) : "The trees are sad, drooping things that "
	     "hang over the swamp, seeming to strangle the life from it.",
	  ]) );
	SetSmell( ([
	  "default" : "The stench of rot mixes with the ocean breeze from the south.",
	  ]) );
	SetListen( ([
	  "default" : "The slither of animals in the muck is a chilling sound.",
	  ]) );
	SetInventory( ([
	  ]) );
}