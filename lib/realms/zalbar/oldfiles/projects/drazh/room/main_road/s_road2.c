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
   "This small stone tiled passageway, which leads north to the main road "
   "of Drazh, ends in a doorway. A small wooden sign hangs next to the "
   "doorway. The walls of the passageway are cracked in more than one place. "
   "The passageway has a high vaulted ceiling. Pieces of the stone from the "
   "ceiling are scattered throughout the passageway. Hanging from both sides "
   "of the passageway are banners of red and black cloth."     );
  SetItems( ([
     ({"main road"}) :
     "The smaller stone tiled passageway heads north towards the main "
     "road of Drazh.",
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
     ({"smithy","doorway","end"}) :
     "At the end of the small passageway, a doorway sits in the south wall. "
     "A small wooden sign hangs outside the doorway.",
     ({"sign"}) :
     "The small wooden sign that is hanging outside the doorway has a "
     "black anvil and hammer drawn onto its surface. This must be the local "
     "smithy for the town.",
     ]) );
  SetItemAdjectives( ([
     "passageway"    : ({"small","stone","tiled"}),
     "road"          : ({"main"}),
     "town"          : ({"small"}),
     "cracks"        : ({"many"}),
     "ceiling"       : ({"high","vaulted"}),
     "banners"       : ({"red","black","cloth"}),
     "sign"          : ({"small","wooden"})
     ]) );
  SetListen( ([
     "default" : 
     "The sounds of striking hammers against metal can be heard.",
     ]) );
  SetSmell( ([
     "default" : 
     "The slight smell of molten metal and hot ashes fills the air.",
     ]) );
  SetInventory( ([
     V_NPC + "citizen" :1,
     ]) );
  SetExits( ([
     "north" : V_ROOM + "main_road/s_road1",
     ]) );
  SetEnters( ([
     "smithy" : V_ROOM + "misc/smithy"
     ]) );
  }
