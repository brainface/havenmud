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
  SetShort("a small passageway");
  SetLong(
	   "This small stone tiled passageway, which leads south from the main road "
	   "of Drazh, heads towards a large hall. The walls of the passageway are cracked "
	   "in more than one place. The passageway has a high vaulted ceiling. Pieces "
	   "of the stone from the ceiling are scattered throughout the passageway. "
	   "Hanging from both sides of the passageway are banners of red and black cloth."
     );
  SetItems( ([
	   ({"main road"}) :
     "The smaller stone tiled passageway heads north to the main "
	   "road of Drazh.",
	   ({"passageway","road","town","drazh","passage"}) : (: GetLong :),
	   ({"walls","wall","cracks","crack"}) :
	   "There are many cracks along the walls of this passage.  This cracks "
	   "must have been from the skavens claiming this town for their own.",
	   ({"hall"}) :
     "This small stone passageway heads south towards a large hall",
	   ({"ceiling"}) :
	   "High above this stone passage is a vaulted ceiling that is missing "
	   "large chunks of stone.",
	   ({"stone","rubble","chunks","pieces"}) :
	   "Rubble from the large pieces of stone that have fallen from the "
	   "ceiling are scattered through the passageway.",
     ({"banners","banner","cloth"}) :
	   "These red and black banners made from cloth, depict an equilateral "
	   "triangle, consisting of three overlapping lines, with one of the "
	   "points facing down hanging from the walls of the passageway.",
     ]) );
  SetItemAdjectives( ([
	   "hall"          : ({"large"}),
     "passageway"    : ({"small","stone","tiled"}),
     "road"          : ({"main"}),
     "town"          : ({"small"}),
     "cracks"        : ({"many"}),
     "ceiling"       : ({"high","vaulted"}),
     "banners"       : ({"red","black","cloth"}),
     ]) );
  SetListen( ([
     "default" : 
     "Footsteps of the watchmen patroling the town can be heard. ",
     ]) );
  SetSmell( ([
     "default" : 
     "The scent of feces and skaven waste fills the air.",
     ]) );
  SetInventory( ([
	   V_NPC + "watchman" :2,
     ]) );
  SetExits( ([
     "north" : V_ROOM + "main_road/main2",
     "south" : V_ROOM + "misc/t_hall",
     ]) );
  }
