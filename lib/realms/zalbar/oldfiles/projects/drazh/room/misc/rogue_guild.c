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
  SetShort("a small dusty corridor");
  SetLong(
	   "This large stone tiled corridor below the town is blocked by debris at "
	   "both ends of the collapsed corridor. The walls of the corridor are cracked "
	   "in more than one place. Pieces of the stone from the ceiling and corridor "
	   "ends are scattered throughout the passage. The room is thick with dust and "
	   "rubble. A set of stone steps, along the south wall, lead back up to the main "
	   "road  of Drazh.");
  SetItems( ([
	   ({"corridor","ends"}) : (: GetLong :),
	   ({"debris","rubble","pieces","stone"}) :
     "Scattered about the corridor floor is stone rubble and debris from the "
     "collapsed ceilings of corridor.",
	   ({"dust"}) :
	   "A thick layer of dust covers everything in the corridor.",
	   ({"walls"}) :
     "There are many cracks along the walls of this passage.  This cracks must "
	   "have been from the when the corridor collapsed at both ends.",
	   ({"steps","set","stairs","south wall"}) :
	   "Along the south wall, an alcove with a set of stone steps leads back up "
	   "to the main road of Drazh.",
	   ]) );
  SetItemAdjectives( ([
     "dust"     : ({"thick"}),
	   "rubble"   : ({"stone"}),
     "steps"    : ({"stone","set"}),
	   "corridor" : ({"large","stone","tiled"}),
	   "ends"     : ({"both"}),
     ]) );
  SetListen( ([
     "default" : 
     "Silence fills the room.",
     ]) );
  SetSmell( ([
     "default" : 
     "The smell of dust wafts the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "rogue_leader" :1,
	   ]) );
  SetExits( ([
      "up" : V_ROOM + "main_road/main2",
      ]) );
}