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
  SetShort("center of town");
  SetLong(
     "This large stone tiled passageway, which is the main road of this small "
	   "town and leads east out of Drazh, ends in a deeply recessed reinforced "
	   "iron double door. A smaller stone tiled passageway leads away from the "
	   "main road, heading north and south. The walls of the passageway are "
	   "cracked in more than one place. The passageway has a high vaulted ceiling. "
	   "Pieces of the stone from the ceiling are scattered throughout the passageway. "
	   "Hanging from both sides of the passageway are banners of red and black cloth."
	   );
  SetItems( ([
	   ({"passageway","road","town","drazh","passage"}) : (: GetLong :),
	   ({"walls","wall","cracks","crack"}) :
	   "There are many cracks along the walls of this passage.  This cracks "
	   "must have been from the skavens claiming this town for their own.",
	   ({"ceiling"}) :
	   "High above this stone passage is a vaulted ceiling that is missing "
	   "large chucks of stone.",
	   ({"stone","rubble","chunks","pieces"}) :
	   "Rubble from the large pieces of stone that have fallen from the "
	   "ceiling are scattered through the passageway.",
     ({"banners","banner","cloth"}) :
	   "These red and black banners made from cloth, depict an equilateral "
	   "triangle, consisting of three overlapping lines, with one of the "
	   "points facing down hanging from the walls of the passageway.",
	   ({"temple","door","doors"}) :
	   "This large set of iron double door is deeply recessed into the stone "
	   "wall. A large black banner hangs from above the doors.",
	   ({"small passage","smaller passageway","smaller passage","small passageway"}) :
	   "This smaller stone tiles passageway travels north and south away from "
	   "the large iron doors.",
	   ({"large banner"}) :
	   "The large black banner hanging above the set of iron doors depicted in "
	   "red is a giant rat head with horns inside a pentagram. This is the symbol "
	   "of Melchezidek, the Prince of Deception. This must lead to the Soirin temple.",
	   ]) );
  SetItemAdjectives( ([
     "passageway"    : ({"large","stone","tiled"}),
     "small passage" : ({"large","stone","tiled"}),
     "road"          : ({"main"}),
     "town"          : ({"small"}),
     "cracks"        : ({"many"}),
     "ceiling"       : ({"high","vaulted"}),
     "banners"       : ({"red","black","cloth"}),
	   "doorway"       : ({"medium","sized"}),
	   "large banner"  : ({"black"}),
	   "door"          : ({"deeply","recessed","iron","double","set","large"}),
     ]) );
  SetListen( ([
     "default" : 
     "Footsteps of the watchmen patroling the town can be heard. ",
     ]) );
  SetSmell( ([
     "default" : 
     "The scent of feces and skaven waster fills the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "honor_guard" : 2,
     ]) );
  AddEnter("temple" , V_ROOM + "temple/entrance");
  SetExits( ([
     "east"  : V_ROOM + "main_road/main3",
	   "north" : V_ROOM + "main_road/n_road1",
	   "south" : V_ROOM + "main_road/s_road1",
     ]) );
}

