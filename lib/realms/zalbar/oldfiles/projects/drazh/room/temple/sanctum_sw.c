// by Dahaka
// Aug 2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"

inherit LIB_ROOM;


static void create() {
  room::create();
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("Corridor of the Seers");
  SetLong(" "
     );
  SetItems( ([
     ]) );
  SetItemAdjectives( ([
	   ]) );
  SetListen( ([
     "default" : 
     "Silence fills the room.",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of blood fills the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "evoker" : 1,
	   ]) );
  SetExits( ([
  	 "northeast" : V_ROOM + "temple/sanctum",
  	 ]) );

}