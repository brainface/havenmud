// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Made this room work and connected it to the area itself.
// This would be perfect to path to Yozrath, or secret 
// tunnel somewhere else. Right now just made it look like 
// a scouted dwarven mine shaft that had no yield so they 
// blasted it.

#include <lib.h>        
#include "../castle.h"          

inherit LIB_ROOM;    
 
static void create() {
::create();
SetShort("a damp cave");
SetLong("This is a dark and damp cavern. It lies behind "
        "a waterfall and is slightly mossy on the floor. "
        "Green lichen grows all about the walls. It appears "
        "that rocks have fallen north and are blocking "
        "the depths of the cavern. Entering the waterfall "
        "opening is the only way to leave. Overall, despite "
        "it being a cave it is quite spacious.");
SetListen("default", "The rushing water from the waterfall "
                     "remains consistant.");
SetSmell("default", "It smells like a pure wet environment.");
SetItems( ([ 
    ({ "cave" }) : (: GetLong :),
    ({ "floor","ground" }) : "The ground is completely soaked "
           "from the incoming water from the waterfall. Green "
           "and thick moss has been growing and taking "
           "advantage along the edge. It extends from "
           "the opening to a cavern in a circle providing "
           "ample room.",
    ({ "rocks","cavern" }) : "Cavern rocks have fallen in "
           "preventing any passage. They are huge in size, "
           "aligned in a pile any mortal could "
           "not move.",
    ({ "water","waterfall" }) : "Water from the waterfall "
           "mists and gushes incremently. It shimmers "
           "softly in natural lighting and looks "
           "extremely clean. An opening can be seen to "
           "the south providing access out.",
     "lichen" : "Lichen stick along the bedrock to complete "
                "the cavern scenery. They are large and "
                "lengthy and connect and weave in patterns "
                "relevant to nature.",
     "walls" : "The walls rise from the floor to the ceiling "
               "in an upside down bowl shape. It is completely "
               "round structurally and is made of bedrock.",
     "rock" : "The rock is thick and appears weathered.",
     "depths" : "The depths of this cave to the north are "
                "blocked off by huge rocks. An old arch lies "
                "full preventing any access into the depths.",
     "moss" : "Green moss grows along the cave edge, it grows "
              "so plush and full.",
     "bedrock" : "The bedrock simply creates this environment. "
                 "It is dark brown in colour and it is very "
                 "compact, it would yield nothing. It is the "
                 "walls, ceiling and ground.",
     "ceiling" : "The ceiling reaches far up and it is made "
                 "of bedrock. It appears sturdy and seems "
                 "sentient beings reinforced it.",
     "opening" : "An opening can be seen through the "
                 "waterfall which provides a way out.",
     "mist" : "Mist from the waterfall flies about "
              "periodically. It is caused by the rushing "
              "water hitting the opening back into the "
              "world.",
     "edge" : "There is a distinct edge along the wall of "
              "bedrock which water trickles and pools along. "
              "Moss grows along it and has been flourishing.",
     "arch" : "The arch housing the large rocks looks old. "
              "It appears to have fallen in on itself from "
              "damage or tragedy.",
     "pool" : "Some water pools along the floor from the "
              "waterfall. Mist and water all assemble, it is "
              "very shallow.",
    ]) );
SetItemAdjectives( ([
    "lichen" : ({ "green" }),
    "moss" : ({ "green" }),
    "bedrock" : ({ "hard" }),
    "walls" : ({ "rock" }),
    "depths" : ({ "cave" }),
    "arch" : ({ "old" }),
  ]) );
SetClimate("indoors");
SetObviousExits("out");
SetExits( ([
  "out" : RUINS_ROOMS "outside3",
]) );

}
void heart_beat() {
  string fire;
  ::heart_beat();
  switch(random(3)) {
    case 0:
      fire = "Massive amounts of water rush past the opening.";
    break;
    case 1:
      fire = "Some mist sprays inside the cave which pools on the floor.";
    break;
    case 2:
      fire = "The gushing water echoes off the cavern walls.";
    break;
}
  eventPrint(fire);
}