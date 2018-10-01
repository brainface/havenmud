#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetClimate("underground");
	SetAmbientLight(0);
	SetShort("a dark sandy tunnel below Yozrath");
	SetLong(""
	  );
	SetInventory( ([
	    HIVE_OBJ "largecrystal"    : 1,
	    ]) );
	SetExits( ([
	   "north"    : HIVE_ROOM "room10",
	   "south"   : HIVE_ROOM "room12",
	   ]) );
	 }
