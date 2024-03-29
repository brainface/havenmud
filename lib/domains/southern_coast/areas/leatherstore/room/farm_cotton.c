#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("Cotton Field");
   SetClimate("temperate");
   SetAmbientLight(30);
   SetExits( ([
     "north"  : LSTORE_ROOM + "craft_hub",
    "west" : LSTORE_ROOM + "farm_hemp",
     "east" : LSTORE_ROOM + "farm_flax",
   ]) );
   SetLong(
     "A seemingly endless cotton field. Other fields lie to the east and west. A wooden "
     "building lies to the north, and beyond that, the Haven Road.",
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
   SetSpecialCrop(STD_FARMING "cotton");
}   
