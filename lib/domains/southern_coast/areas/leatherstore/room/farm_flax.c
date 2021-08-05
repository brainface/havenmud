#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("Flax Field");
   SetClimate("temperate");
   SetAmbientLight(30);
   SetExits( ([
     "west"  : LSTORE_ROOM + "farm_cotton",
   ]) );
   SetLong(
     "A seemingly endless flax field. Other fields lie to the west. A wooden "
     "building lies to the northwest, and beyond that, the Haven Road.",
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
   SetSpecialCrop(STD_FARMING "flax");
}   
