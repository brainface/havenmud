#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetClimate("underground");
	SetAmbientLight(0);
	SetShort("the Queen's Lair");
	SetLong(""
	  );
	SetInventory( ([
	    HIVE_OBJ "largecrystal"    : 1,
	    ]) );
	SetExits( ([
	   "west"     : HIVE_ROOM "room19",
	   ]) );
	 }
	
