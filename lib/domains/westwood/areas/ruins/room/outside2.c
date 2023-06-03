// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 6.16.13
// Created this room

#include <lib.h>  
#include "../castle.h"          

#define WESTWOOD "/domains/westwood/virtual/westwood/"      
      
inherit LIB_ROOM;       
 
static void create() {
::create();
SetShort("near some ancient ruins");
SetLong("The grasslands here appear tame and nourished "
        "despite the tall Westwood trees blocking out "
        "most of the natural lighting. To the east an "
        "old castle rests, secured by an old ruined moat. "
        "Medium sized boulders litter the ground "
        "along a beaten path which leads north toward a "
        "large lake. To the southwest and western directions, "
        "the standard Westwood forest is seen casually "
        "hiding its secrets. A drawbridge can be viewed to the "
        "south which looks to be an entrance built in this "
        "shoddy and ancient structure.");
SetExits( ([
      "south" : RUINS_ROOMS "drawbridge",
      "north" : RUINS_ROOMS "outside3",
       "west" : WESTWOOD + "24,30",
  "southwest" : WESTWOOD + "24,29",  
]) ); 
SetInventory( ([ 
                RUINS_NPC "cleric" : 1,
            ]) );
SetListen("default", "Creatures from the Westwood chitter "
                     "and squawk above.");
SetSmell("default", "Fresh air from the woods mix with the "
                    "odorous moat.");
SetClimate("temperate");
SetAmbientLight(35);
SetItems( ([ 
    ({ "grasslands","field" }) : (: GetLong :),
    ({ "Westwood","westwood" }) : "The definitive barrier "
       "of Westwood trees is seen to the west. Pine trees "
       "which have grown for ages provide shelter and "
       "secrets within. Tree roots grow rampant through "
       "the small brush.",
    ({ "east","castle" }) : "The east castle appears "
       "in rough shape, but it is still protected by "
       "a ruined moat. Grass lines the shore of the "
       "green stagnant water.",
    ({ "drawbridge","entrance" }) : "A large wooden "
       "entrance can be seen a distance in the south. "
       "At a glance it is difficult to discern from this "
       "distance.",
     "ruins" : "The ruins remain strong despite the "
               "neglect of the structures moat. Water "
               "damage appears apparent along the "
               "shore and aged brick composes the wall. "
               "Regardless of weathering it still looks "
               "like a solid shelter.",
     "trees" : "Trees from the Westwood reach into this "
               "grasslands but they are few and far "
               "between inside this forest. They are "
               "pine trees with aged roots that have "
               "grown wild in their lifetimes. They "
               "are indeed ancient. In the west, they "
               "grow thicker creating a border.",
     "window" : "A small triangular window in the "
                "ruins to the east has a sizeable amount "
                "of smoke pluming out of it.",
     "smoke" : "The black smoke releases from inside "
               "the ruins into the air above.",
     "lighting" : "The natural lighting illuminates "
                  "this field.",
     "moat" : "The green ruined moat still offers "
              "protection to the castle and stretches "
              "to the south. A good portion of the "
              "water has dried up near this corner but "
              "the soil remains murky.",
     "boulders" : "Medium boulders line the path with "
                  "no particular design or pattern. "
                  "They are made of white rock and "
                  "stand taller than any orc.",
     "path" : "The beaten path leads north to an area "
              "less dreadful. Grass borders it rather "
              "distinctly and it is brown packed soil.",
     "structure" : "The structure of the ruins appears "
                   "in tact despite abuse from the "
                   "outside elements and neglected moat.",
     "roots" : "The tree roots grow wild in the Westwood.",
     "water" : "It is stale green water in the moat. Some "
               "portions have dried up and leave thick "
               "sections of mud.",
     "mud" : "Dirt mixed with the water has made an area "
             "around the moat solid and shapes its very "
             "being. It doesnt appear too deep.",
     "stone" : " The stone is yellowed from age and "
                 "is quite porous.",
     "wall" : "The wall starts at the corner of the moat "
              "from the dry section and stretches south "
              "near an entrance.",
//     "" : ".",
    ]) );
SetItemAdjectives( ([
    "ruins" : ({ "ancient" }),
    "boulders" : ({ "medium" }),
    "moat" : ({ "old","ruined","odorous" }),
    "path" : ({ "beaten","used" }),
    "stone" : ({ "porous","yellow" }),
//    "" : ({ "","","","" }),
  ]) );
}