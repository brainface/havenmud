#include <lib.h>
#include <std.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("inside the burial mound");
	SetExits( ([
	  "out" : GWONISH_ROOM "gw05",
	  ]) );
	SetSmell( ([
	  "default" : "The stench of rotting meat is thick and rancid.",
	  ]) );
	SetListen( ([
	  "default" : "It is quiet here.",
	  ]) );
  SetLong("The burial mound is a deep hole in the ground covered with a thin "
          "covering of mud and adobe. Scattered around the floor are hunks of "
          "rotting meat, some of which appears to be the corpses of lizardmen. "
          "A small amount of light streams in from the outside, making this "
          "dim cave that much more sinister.");
  SetClimate("underground");
  SetAmbientLight(20);
  SetProperty("NoAttack",1);
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}
