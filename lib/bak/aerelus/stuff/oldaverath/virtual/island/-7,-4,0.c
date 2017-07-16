/*  Connection room to Kobolds */
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("a dark tunnel");
	SetClimate("underground");
	SetExits( ([
	  "north" : "-7,-3,0",
	  "down"  : "-7,-4,-1",
	  ]) );
}
