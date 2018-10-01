// by Dahaka
// Aug 2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  room::create();
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("intersection of main road");
  SetLong(
     "This large stone tiled passageway is the main road of this small town, "
	   "which heads west and east in Drazh. Off to the south a smaller stone "
	   "tiled passage leads in that direction. The walls of the passageway are "
	   "cracked in more than one place. The passageway has a high vaulted "
	   "ceiling. Pieces of the stone from the ceiling are scattered throughout "
	   "the passageway. Across from the smaller passageway along the north wall "
	   "is a small doorway with a set of stone stairs leads into the darkness "
	   "below. Hanging from both sides of the passageway are banners of red "
	   "and black cloth."
	   );
  SetItems( ([
	   ({"small passage","smaller passageway","smaller passage","small passageway"}) :
     "This smaller stone tiled passageway heads south away from the main "
	   "road of Drazh.",
	   ({"north wall","doorway","set","stairs"}) :
	   "Along the north wall of the main road, a set of stone stairs can be "
	   "seen through a small doorway.  The stone stairs lead down into the "
	   "darkness.",
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
     "passageway"    : ({"large","stone","tiled"}),
     "road"          : ({"main"}),
     "town"          : ({"small"}),
     "cracks"        : ({"many"}),
     "ceiling"       : ({"high","vaulted"}),
     "banners"       : ({"red","black","cloth"}),
	   "small passage" : ({"large","stone","tiled"}),
	   "doorway"       : ({"small"}),
	   "stairs"        : ({"set","stone"}),
     ]) );
  SetListen( ([
     "default" : 
     "Footsteps of the watchmen patroling the town can be heard. ",
     ]) );
  SetSmell( ([
     "default" : 
     "The slight scent of ale wafts the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "citizen"     : 2,
	   V_NPC + "black_agent" : 1,
     ]) );
  AddEnter("doorway", V_ROOM + "misc/rogue_guild", (: PreExit :));
  SetExits( ([
     "east"  : V_ROOM + "main_road/main1",
     "west"  : V_ROOM + "main_road/main3",
	   "south" : V_ROOM + "main_road/d_road1",
     ]) );
}


int PreExit (string dir) {
  object who;
  who = this_player();
  if (this_player()->GetSize() > 16) 
  {
	  who->eventPrint("You are too big to fit through the doorway.");
	  return 0;
  }
  else return 1;
}