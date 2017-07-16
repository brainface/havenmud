
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("southwest");
  SetShort("a dead end in the cave");
  SetLong(
          "The tunnel turns into this dead end. A thin layer of "
          "black sand litters the ground, mostly in the corners. "
          "This section of the cave is simple and barren with the "
          "exception of the sand.");
  SetInventory( ([
                 TOWER_NPC "wcorpse" : 2, 
				  ]) );
  SetExits( ([
            "southwest"     : TOWER_ROOMS "cave09",
           ]) );
  SetSmell( ([
            "default" : "It smells of burnt sand somewhat.",
           ]) );
  SetListen( ([
            "default" : "A faint breeze is heard from the southwest."
           ]) );
  SetItems( ([
     "ceiling" : "The ceiling is rounded and bends to the southwest.",
	 "corners" : "Natural cave formation makes corners which the "
	             "black sand piles up.",
     "walls"   : "The walls have vertical ridges in them from natural "
                 "cave formation.",
     "sand"    : "The sand has accumulated from the draft southwest "
                 "to here. It is black and has very small grains.", 
     "wall"    : "Made of natural rock, it rounds from the floor and "
                 "reaches to the ceiling.",
	 "clay"    : "Soft black clay creates the ground here.",
    ({ "ground", "floor" }) : "It is made of a dark packed clay and "
                               "lines the cavern ground. The ground "
                               "is covered in dark grains of sand.",
              ]) );
    SetItemAdjectives( ([
    "sand" : ({ "layer","black","small" }),
    "wall" : ({ "rock" }),
    "walls" : ({ "rock" }),
    "corners" : ({ "cave" }),
      ]) );
}