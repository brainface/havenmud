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
  SetShort("the main road in town");
  SetLong(
     "This large stone tiled passageway is the main road of this small town, "
	   "which heads west and east in Drazh. The walls of the passageway are "
	   "cracked in more than one place. The passageway has a high vaulted "
	   "ceiling. Pieces of the stone from the ceiling are scattered throughout "
	   "the passageway. Hanging from both sides of the passageway are banners "
	   "of red and black cloth. In the middle of the north wall, a small wooden "
	   "sign is hanging next to a doorway leading off the main road."
	   );
  SetItems( ([
	   ({"sign"}) :
     "Drawn upon this small wooden sign is a few gold coins dropping from "
     "one hand to another hand. This must be a place of trade and banking.",
	   ({"market","shop","store","bank","north wall","doorway"}) :
	   "A small wooden sign hangs next to a stone arched doorway, which leads "
	   "off the main road into a smaller room.",
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
     ]) );
  SetItemAdjectives( ([
     "passageway" : ({"large","stone","tiled"}),
     "road"       : ({"main"}),
     "town"       : ({"small"}),
     "cracks"     : ({"many"}),
     "ceiling"    : ({"high","vaulted"}),
     "banners"    : ({"red","black","cloth"}),
	   "doorway"    : ({"medium","sized"}),
	   "sign"       : ({"small","wooden"}),
     ]) );
  SetListen( ([
     "default" : 
     "Footsteps of the watchmen patroling the town can be heard. ",
     ]) );
  SetSmell( ([
     "default" : 
     "Wafting in the air is the slight smell of feces and skaven waste.",
     ]) );
  SetInventory( ([
	   V_NPC + "citizen" : 2,
     ]) );
  AddEnter("market", V_ROOM + "misc/market");
  SetExits( ([
     "east"  : V_ROOM + "main_road/main2",
     "west"  : V_ROOM + "main_road/main4",
     ]) );
}

