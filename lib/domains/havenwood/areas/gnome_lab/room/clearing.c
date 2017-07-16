#include <lib.h>
#include "../gnome_lab.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a large clearing");
  SetNightLight(25);
  SetClimate("temperate");
  SetLong(
	  "The forest opens up into this large clearing at the base "
	  "of a very tall tree. A campfire has been set up in the "
	  "center of the clearing with large rocks tossed around it. "
	  "Near the fire and ready for use, three piles of wood are "
      "stacked halfling high. A single torch stands near the "
	  "enormous tree, like a soldier standing at attention. A "
	  "large wooden ladder is leaning against the tree."); 
  SetItems( ([ 
	  "torch" : 
	  "This large torch has been rammed into the ground to "
	  "withstand being knocked over.",
	  ({"pile","piles","wood"}) :
	  "The three piles are neatly stacked near arms reach of "
	  "the campfire.",
	  ({"flame","campfire","flames","fire"}) :
	  "The campfire has a large flame to keep the forest wildlife away.",
	  ({"clearing","center","base"}) : (:GetLong:),
	  "tree" :
	  "This very tall tree climbs up over the canopy of the forest.",
	  "forest" : (:GetLong:),
	  "trees" :
	  "The trees surround the clearing like a stockade fence.",
	  ({"rock","rocks"}) :
	  "The large rocks surround the campfire like chairs around a "
	  "dinner table.",
	  ]) );
  SetItemAdjectives( ([
	 "wood" : ({"pile of","piles of"}),
	 "piles" : "three",
     "clearing" : ({"large","center"}),
     "tree" : ({"enormous","tall","very tall"}),
	 "torch" : "single",
     ]) );
  SetListen( ([
     "default" : 
	 "In the air, the chattering of squirrels can be heard."
     ]) );
  SetSmell( ([
	 ({"torch","flame"}) :
     "The scent of burning wood fills your nostrils.",
     "default" :
	 "The scent of burning wood fills the air.",
     ]) );
  SetInventory( ([
	  G_OBJ + "ladder" : 1,
	  G_NPC + "dwarf"  : 3,
	  ]) );
  SetExits( ([
	 "east" : EXIT,
	 ]) );
 }
