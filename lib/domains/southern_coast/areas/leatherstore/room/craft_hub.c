#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("The Crafting Hub");
   SetClimate("indoors");
   SetNewsgroups( ({ "player.crafting" }) );
   SetAmbientLight(30);
   SetExits( ([
     "north" : LSTORE_ROOM + "leatherstore",
     "east"  : LSTORE_ROOM + "craft_textile",
     "west"  : LSTORE_ROOM + "craft_leather",
     "out"   : LSTORE_ROOM + "farm_cotton",
   ]) );
   SetLong(
     "An unfinished room in the back of Tornys' Shop.\n"
     "This isn't finished! Get out of here! It's boring!"
   );
   SetItems ( ([
	]) );
   SetItemAdjectives( ([
	]) );
   SetInventory( ([
     LSTORE_OBJ "donation" : 1,
		   ]));
   SetSmell( ([
     "default" : "It smells unfinished",
      ]) );
}   
