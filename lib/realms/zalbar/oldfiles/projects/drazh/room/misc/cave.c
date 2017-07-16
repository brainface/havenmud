// by Dahaka
// 7-2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("cave of garbage");
  SetLong(
	   "This large cave is full of the waste from the denizens of this "
	   "small town.  The only way in and out of the cave is through the "
	   "entrance in the south wall. Every hole in the cave floor is filled "
	   "either feces or wasted food from the citizens of Drazh."
	   );
  SetItems( ([
	   ({"cave"}) : (:GetLong:),
	   ({"waste","feces","food","garbage"}) :
     "The cave floor is covered in feces and wasted food from the "
	   "citizens of the town.",
	   ({"entrance","exit"}) :
	   "In the south wall of the cave is the entrance and exit to "
	   "this cave. Looking out it leads back to Drazh.",
	   ({"hole","holes","floor"}) :
	   "On the floor of this cave is pocketed with holes of various "
	   "sizes, which are filled with garbage and other waste from "
	   "the denizens of this small town.",
	   ]) );
  SetItemAdjectives( ([
	   "cave" : ({"large"}),
	   "food" : ({"wasted"}),
     "hole" : ({"every"}),
	   "floor" : ({"cave"}),
     ]) );
  SetListen( ([
     "default" : 
     "Scurrying of rats can be heard throughout the cave.",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of decaying garbage fills in the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "gaint_rat" : random(4) + 1,
	   V_NPC + "small_rat" : random(6) + 2,
     ]) );
  SetExits( ([
     "out" : V_ROOM + "main_road/n_road2",
     ]) );
  }