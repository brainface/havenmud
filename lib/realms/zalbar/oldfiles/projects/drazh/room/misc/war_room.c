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
  SetShort("war room");
  SetLong(
     "This small square chamber is sparsely furnished with just a large round "
	   "wooden table. A large lantern hangs from the ceiling to cast a light "
	   "around this room. The ceiling and wall have a few cracks running across "
	   "their surfaces. A dark draped cloth covers the doorway in the north wall, "
	   "which leads back to the watchman's training hall. A large black banner and "
	   "a smaller red banner hang from the middle of the south wall."
     );
  SetItems( ([
	   ({"chamber","room","war room"}) : (: GetLong :),
	   ({"south wall"}) :
	   "Along the south wall of this square chamber are two banners, one large "
	   "black banner and the other is a small red one.",
	   ({"table"}) : 
	   "This large round wooden table sits in the middle of this chamber. The "
	   "table top of the table looks scratched and beat up.",
	   ({"ceiling","wall","walls","cracks","surfaces"}) :
	   "The four stonewalls and ceiling of this small chamber has many cracks "
	   "running across there surfaces. These cracks must have been due to the "
	   "fighting that must have ensued within the walls of Drazh.",
	   ({"cloth","drape"}) :
	   "This dark thick cloth drapes down above the door to keep out the noise.",
	   ({"doorway","north wall","hall"}) :
	   "The stone arched doorway leads back into the training hall of Drazh.",
	   ({"small banner"}) :
	   "This banner is made from a red cloth, which depicts an equilateral "
	   "triangle, consisting of three overlapping lines, with one of the "
	   "points facing down hanging.",
	   ({"large banner"}) :
	   "The large black banner hanging in the middle of the room, depicted "
	   "in red embroidery, a giant rat head with horns inside a pentagram. "
	   "This is the symbol of Melchezidek, the Prince of Deception.",
	   ({"shadow","shadows"}) :
	   "The dancing shadows from the large lantern look as if they jump "
	   "from wall to wall.",
	   ({"lantern"}) :
	   "This large lantern brightens this room cast eerie shadows against "
	   "the wall.",
     ]) );
  SetItemAdjectives( ([
	   "chamber"      : ({"stone","small","square"}),
     "hall"         : ({"training","watchman"}),
     "doorway"      : ({"stone","arched"}),
     "south wall"    : ({"far"}),
	   "table"        : ({"small","round","wooden"}),
	   "chair"        : ({"high","back","highback","wooden"}),
	   "ceiling"      : ({"stone"}),
	   "lantern"      : ({"large"}),
	   "shadow"       : ({"dancing"}),
	   "large banner" : ({"black"}),
	   "small banner" : ({"red"}),
	   ]) );
  SetListen( ([
     "default" : 
     "Silence fills the room.",
     ]) );
  SetSmell( ([
     "default" : 
     "The scent of burning oil wafts in the the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "fighter_leader"        : 1,
     V_NPC + "stormvermin_commander" : 1,
	   ]) );
  SetExits( ([
     "out" : V_ROOM + "misc/t_hall",
	   ]) );

}