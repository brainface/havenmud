
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

int PreExit();

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("west, out");
  SetShort("near an exit");
  SetLong(
          "The inside of the cave is somewhat man made. The ceiling "
          "has been carved out by a hollow object. Sparse puddles of "
          "water can be seen undisturbed near the cavern walls. To the "
          "west the cave seems to get even darker and small granite "
          "rocks litter the ground offering little tread in this "
          "flat cave. An opening in the southeast cavern wall would "
		  "assist in any egress.");
  SetExits( ([
             "west"      : TOWER_ROOMS "cave03",   
           ]) );
  SetSmell( ([
            "default" : "It reaks of decayed corpses and moldy water.",
           ]) );
  SetListen( ([
            "default" : "An occasional drip is heard."
           ]) );
  SetItems( ([
     "ceiling" : "It is evident that the ceiling was carved by a bowl "
                 "or hands in haste. It contains a dark gray color and "
                 "is ridgid in numerous areas.",
     "puddles" : "They get their water from the slow leak in the "
                 "soil walls and form near the walls.",
     "walls"   : "The walls are made of a soft soil, chunks have been "
                 "ripped out and moved some time ago.",
     "rock"    : "The small granite rock have been grinded down from "
                 "travel.",
	 "opening" : "An opening in the cave walls leads out of this cave.",
    ({ "ground", "floor" }) : "It is covered in various shapes of "
                 "granite rocks. The base of the ground is a black "
                 "clay that has been packed flat. In sparce locations "
                 "some puddles can be seen.",
    ({ "water"}) : "The water lay undisturbed for sometime "
                               "and remains stagnant, full of "
                               "sediment.",
    ({ "rocks" }) : "The rocks litter the "
                 "floor all over, some have even been ground to a small "
                 "powder or even smaller granite rocks.",
              ]) );
  SetItemAdjectives( ([
    "ceiling" : ({ "roof","up","gray"}),
    "puddles" : ({ "water" }),
    "rock" : ({ "granite","small" }),
    "ground" : ({ "granite","flat" }),
    "water" : ({ "puddle" }),
    "rocks" : ({ "granite" }),
  ]) );
 AddExit("out", TOWER_ROOMS "cave01", (: PreExit :));
  }
// Code to prevent wanderers out of the cave
int PreExit() {
  if (this_player()->id("undead_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}