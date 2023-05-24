#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetClimate("underground");
	SetAmbientLight(0);
	SetShort("a dark sandy tunnel below Yozrath");
	SetLong(ROOM_DESC_TUNNEL
	  );
	SetInventory( ([
	    HIVE_OBJ "largecrystal"    : 1,
	    ]) );
	SetExits( ([
	   "north"    : HIVE_ROOM "room14",
	   "south"    : HIVE_ROOM "room26",
	   "east"     : HIVE_ROOM "room16",
	   "west"     : HIVE_ROOM "room21",
	   ]) );
	 }
