// by Dahaka
// Aug 2004

#include <lib.h>
#include "../../drazh.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(40);
  SetTown("Drazh");
  SetShort("Drazh Smithy");
  SetLong(
     "This large stone chamber has a large forge against the south wall. "
	   "Dark scorch marks and ashen stains the walls around the room. A large "
	   "black steel anvil sits in the middle of the chamber awaiting its "
	   "master. The stone arched doorway leads back into Drazh."
     );
  SetItems( ([
     ({"smithy","chamber","room"}) : (:GetLong:),
     ({"forge","tools","south wall"}) : 
     "This large stone forge is set into the middle of the south wall. "
	   "There are many tools around the forge that help the master smith "
	   "do his job.",
     ({"marks","stains","mark","stain"}) : 
	   "The dark scorch marks and ashen stains around the room must be "
     "from the flames of the forge.",
	   ({"anvil"}) :
	   "This large black steel anvil is setup in the middle of the smithy. ",
	   ({"doorway","north wall","hall"}) :
	   "The stone arched doorway leads back into Drazh.",     
     ]) );
  SetItemAdjectives( ([
	   "chamber" : ({"large","stone"}),
	   "forge"   : ({"large","stone"}),
	   "tools"   : ({"many"}),
	   "marks"   : ({"dark","scorch"}),
	   "stains"  : ({"ashen"}),
	   "anvil"   : ({"large","black","steel"}),
	   "doorway" : ({"stone","archway"}),
     ]) );
  SetListen( ([
     "default" : 
     "The sounds of striking hammers against metal echoes thoughout "
     "the room. "
     ]) );
  SetSmell( ([
     "default" : 
     "The smell of molten metal and hot ashes fills the air. "
     ]) );
  SetInventory( ([
     V_NPC + "apprentice" : 1,
     V_NPC + "smith"      : 1,
     ]) );
  SetExits( ([
     "out" : V_ROOM + "main_road/s_road2",
     ]) );
  SetProperties( ([
     "metal working"   : 1,
     "natural working" : 1,
     "wood working"    : 1,
     "leather working" : 1,
     "textile working" : 1,
     "mithril working" : 1,
     ]) );
  }
