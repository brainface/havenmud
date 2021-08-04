#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("Cotton Farm");
   SetClimate("temperate");
   SetAmbientLight(30);
   SetExits( ([
     "north"  : LSTORE_ROOM + "craft_hub",
   ]) );
   SetLong(
     "A seemingly endless cotton farm.",
   );
   SetItems ( ([
	]) );
   SetItemAdjectives( ([
	]) );
   SetInventory( ([
		   ]));
   SetSmell( ([
     "default" : "It smells unfinished",
      ]) );
}   
