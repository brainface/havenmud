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
  SetShort("landing");
  SetLong(
	  "Climbing the winding staircase to the next floor, one arrives at "
	  "immense blackened iron bound double doors.  Next to the door is a "
	  "pitted, tarnished, chipped bronze gong, massive in size. "

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
	  V_NPC + "council_commander" : 1,
	 ]) );
  SetExits( ([
	 "down" : V_ROOM + "temple/entrance",
	 "west" : V_ROOM + "temple/chamber",
     ]) );

}