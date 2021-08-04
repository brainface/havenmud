#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("Textile Room");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetExits( ([
     "west"  : LSTORE_ROOM + "craft_hub",
   ]) );
   SetLong(
     "An unfinished room in the back of Tornys' Shop"
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
