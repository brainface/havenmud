#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("a meeting point of paths");
	SetExits( ([
	  "north" : GWONISH_ROOM "gw10",
	  "east"  : GWONISH_ROOM "gw07",
	  "west"  : GWONISH_ROOM "gw05",
	  "south" : GWONISH_ROOM "gw03",
	  ]) );
	SetLong(
	  "The pathways through the swamp meet in a four way "
	  "intersection here. Though this portion of the swamp "
	  "looks no more inhabitable than any other part, there "
	  "does seem to be an actual stone building here. The stone "
	  "building has crude black markings on it denoting some sort "
	  "of evil magic. Off to the east lies what seems to be the "
	  "center of the village, while to the west is an area that "
	  "serves as a local cemetery. Pathways also lead north and "
	  "south."
	  );
	SetSmell( ([
	  "default" : "The stench of rotting vegetation mixes with an "
	              "unpleasant smell of rotting meat.",
	  ]) );
	SetListen( ([
	  "default" : "Strange whispers come from the stone building.",
	  ]) );
	SetItems( ([
	  "building" : "The building is the home of the Gwonish sect of "
	               "necromancers.",
	  ]) );
	SetItemAdjectives( ([
	  "building" : ({ "stone" }),
	  ])  );
	SetEnters( ([
	  "building" : GWONISH_ROOM "necros",
	  ]) );
	SetInventory( ([
	  GWONISH_NPC "shopkeep" : 1,
	  ]) );
}