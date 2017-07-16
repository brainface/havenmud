
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("north, south");
  SetShort("near an exit");
  SetLong(
          "The ground has unevened slightly near an exit of the "
          "cave. The opening appears to be natural rock which "
          "has been formed to make way outside. Patches of grass "
          "have broken through the rock ground creating minor "
          "cracks in the surface.");
  SetExits( ([
            "north"  : TOWER_ROOMS "tout01",
            "south"  : TOWER_ROOMS "cave17",
           ]) );
  SetSmell( ([
            "default" : "Fresh air breeses through the opening.",
           ]) );
  SetItems( ([
     "ceiling" : "It cones down with the walls to form the opening "
                 "to the north.",
     "walls"   : "The walls appear under stress or pushed back "
                 "slightly by a constant force. The closer the "
                 "walls are to the opening the more they are "
                 "in ruins.",
     "rock"    : "It is gray and makes up the ground and walls.",
     "cracks"  : "Patches of grass have crept through some cracks "
                 "in the ground.",
	 "wall" : "The wall looks to be under some pressure. It "
	          "bows slightly. It is made of gray rock.",
     "surface" : "It has cracks in it from the grass.",
    ({ "exit", "opening" }) : "An opening rests in the north wall "
                               "exiting the cave.",
    ({ "grass" }) : "Patches of normal green grass "
                    "flourish in this cave "
                    "near the opening.",
    ({ "ground", "floor" }) : "The ground is packed with the black "
                               "clay and rounds to the exit where "
                               "natural soil is seen. Along the "
                               "surface of the ground some patches "
                               "of grass have grew out of the "
                               "surface.",
		"clay" : "The black clay ends here and does not leave "
                 "this dark cave.",		
              ]) );
    SetItemAdjectives( ([
    "grass" : ({ "green","patches" }),
    "rock" : ({ "gray" }),
    "clay" : ({ "black" }),
  ]) );
}