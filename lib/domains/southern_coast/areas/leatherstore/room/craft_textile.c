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
     "A workroom in the back of Tornys' shop. Open "
     "shuttered windows allow an intermittent breeze "
     "to flow through."
   );
   SetItems ( ([
   ]) );
   SetItemAdjectives( ([
   ]) );
   SetInventory( ([
     LSTORE_OBJ + "sign_textile" : 1,
     STD_CRAFTING + "stations/loom" : 1,
     STD_CRAFTING + "stations/spinny_wheel" : 1,  
     STD_CRAFTING + "stations/dye_vat" : 1,  
   ]));
   SetSmell( ([
     "default" : "The strong but not unpleasant scent of wet "
       "fabric and concentrated dyes fills the room.",
   ]) );
}

