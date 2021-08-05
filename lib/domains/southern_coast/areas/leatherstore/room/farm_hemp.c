#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("Hemp Field");
   SetClimate("temperate");
   SetAmbientLight(30);
   SetExits( ([
     "east"  : LSTORE_ROOM + "farm_cotton",
   ]) );
   SetLong(
     "A seemingly endless hemp field. Other fields lie to the east. A wooden "
     "building lies to the northeast, and beyond that, the Haven Road.",
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
   SetSpecialCrop(STD_FARMING "hemp");
}   
