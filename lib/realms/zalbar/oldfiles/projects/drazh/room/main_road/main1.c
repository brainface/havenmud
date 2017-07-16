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
  SetShort("the main road in town");
  SetLong(
	   "This large stone tiled passageway is the main road of this small town, "
	   "which heads west deeper into Drazh. The walls of the passageway are "
	   "cracked in more than one place. The passageway has a high vaulted ceiling. "
	   "Pieces of the stone from the ceiling are scattered throughout the "
	   "passageway. Hanging from both sides of the passageway are banners of red "
	   "and black cloth. A small sign hangs near a doorway along the south wall "
	   "of the road."
	   );
  SetItems( ([
	   ({"passageway","road","town","drazh"}) : (: GetLong :),
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
	   ({"sign"}) :
	   "A drawing on the small sign depicts a giant rat lying on its back "
	   "while holding two empty mugs. This must be the local tavern.",
	   ({"doorway","south wall","tavern"}) :
     "Along the south wall a small sign is hanging above a draped doorway.",
     ]) );
  SetItemAdjectives( ([
	   "passageway" : ({"large","stone","tiled"}),
	   "road"       : ({"main"}),
	   "town"       : ({"small"}),
     "cracks"     : ({"many"}),
	   "ceiling"    : ({"high","vaulted"}),
     "banners"    : ({"red","black","cloth"}),
	   "sign"       : ({"small"}),
     ]) );
  SetListen( ([
     "default" : 
     "The clattering of drunken souls can be heard. ",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of ale fills the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "watchman"        : 2,
	   V_NPC + "wander_watchman" : 2,
     ]) );
  SetEnters( ([
	   "doorway" : V_ROOM + "misc/tavern"
     ]) );
  SetExits( ([
     "west" : V_ROOM + "main_road/main2",
     ]) );
  /*AddExit(
	  "east" , V_ROOM + "tunnel/t8", (:PreExit:),
	  );*/
}


int PreExit () {
  if (this_player()->id("wander")) return 0;
    else return 1;
}