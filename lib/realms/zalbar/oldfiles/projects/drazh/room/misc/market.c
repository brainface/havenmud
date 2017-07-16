// by Dahaka
// Aug 2004

#include <lib.h>
#include "../../drazh.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(50);
  SetTown("Drazh");
  SetShort("Market of Drazh");
  SetLong(
     "This large square room has a lantern hanging from every wall, which "
	   "brightens the room. A large wooden counter divides the room into two. "
	   "Two large banners hang next to the lantern on the north wall. The walls "
	   "have a few cracks and scratches running along its surface. A doorway on "
	   "the south wall leads back into main passage of Drazh."
     );
  SetItems( ([
	   ({"room","merchantplace","market"}) : (:  GetLong :),
	   ({"lantern","lanterns"}) :
     "The oil lanterns cast a golden glow around the room while hanging "
	   "around the room.",
	   ({"glow"}) :
	   "The oil lanterns, which hang around the room, cast a golden glow "
	   "about the room.",
	   ({"wall","walls","cracks","surface","scratches"}) :
	   "The wall is marked up with cracks and scratches from the fighting "
	   "the skaven did while claim this town as their own.",
	   ({"counter"}) :
	   "This large dark wooden counter separates the merchants from their "
	   "customers that visit the shop.",
	   ({"banners","north wall"}) :
	   "The lantern on the north wall hangs between two large hanging "
	   "banners. The banner of the left is very colorful while the one "
	   "on the right is very drab.",
	   ({"left banner"}) :
	   "Embroidered into the blue cloth of this large banner is an open "
	   "money pouch with coins spilling from the open. This must be the "
	   "local bank for the town.",
     ({"right banner"}) :
	   "The brown drab cloth banner that hangs from the wall depicts a "
	   "scale for measuring. This must be the local trade shop for the town.",
	   ({"doorway","south wall","passage"}) :
	   "The doorway in the middle of the south wall leads back to the main "
	   "passage of Drazh.",
     ]) );
  SetItemAdjectives( ([
	   "room"    : ({"large","square"}),
	   "lantern" : ({"oil"}),
	   "glow"    : ({"golden"}),
	   "wall"    : ({"every"}),
	   "cracks"  : ({"few"}),
	   "counter" : ({"large","wooden"}),
	   "banners" : ({"large","two"}),
	   "passage" : ({"main"}),
     ]) );
  SetListen( ([
     "default" : 
     "The sounds of citizens bartering fills the air."
	 ]) );
  SetSmell( ([
     "default" : 
     "A musty smell hangs in the air."
     ]) );
  SetInventory( ([
     V_NPC + "banker" : 1,
     V_NPC + "trader" : 1,
     ]) );
  SetExits( ([
     "out" : V_ROOM + "main_road/main3",
     ]) );
}
