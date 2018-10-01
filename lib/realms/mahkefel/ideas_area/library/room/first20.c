/* Arcanith Library first20
 *
 *oken tab
 */
#include <lib.h>                   

// mikes includes dir
#include "../arc_library.h" 

// must be in all rooms
inherit LIB_ROOM;      

static void create() {
  // get it started   
  ::create();     

  SetClimate("indoors");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("an old reading room");           
  SetLong(
    "Chairs are arranged here in a perfect circle around a broken table. On "
    "the ceiling, a flickering glass globe hangs precariously from a silver "
    "chain. To the east a bare window stares directly into a mound "
    "of obscuring rubble. Cool air wafts in from the west, and the lobby "
    "lies back toward the south."
  );                                                                          


  SetItems( ([
    ({"floor","floorboards"}) :
      "The floor here is largely intact.",
    ({"table"}) :
      "The table's legs have all broken off.",
    ({"ceiling"}) :
      "On the ceiling, a flickering glass glove hangs precariously from a "
      "silver chain.",
    ({"window","street","building","rubble"}) :
      "The collapse of a neighboring building has spoiled the view of the "
      "street outside.",
    ({"chairs"}) :
      "The sturdy wooden frames of these chairs were apparently built to "
      "last. The cushions have long ago rotten away, however.",
    ({"chain"}) :
      "The tarnished chain is barely holding together.",
    ({"globe"}) :
      "The glass globe is cracked and faded, but still occasionally "
      "flickers with light.",
  ]) );                                                                       


  SetItemAdjectives( ([
    "table" : ({"broken"}),
    "window" : ({"bare","obscuring"}),
    "chain" : ({"silver","tarnished"}),
    "globe" : ({"glass","flickering"}),
  ]) );

  SetListen( ([
    "default" : "The floorboards settle and creak.",
  ]) );

  SetSmell( ([
    "default" : "Dust is heavy in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "dust_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "wind_mephit" : random(3),
  ]) );

  SetExits( ([
    "south" : "first21",
    "west"  : "first10",
  ]) );

}

