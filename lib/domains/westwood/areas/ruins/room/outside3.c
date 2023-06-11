// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
// Lake Pokenay - A commonly known "Vein of Amelia"
//                in the Westwood.

#include <lib.h>   
#include "../castle.h"         

#define WESTWOOD "/domains/westwood/virtual/westwood/"
#define STD_FISH "/std/fish/"   
   
inherit LIB_FISHING;        
 
static void create() {
::create();
 SetShort("a shimmering lake");
 SetLong("The giant towering rockface to the north forms a "
        "waterfall which crashes down into a crystal clear "
        "lake. The lake has a soft shimmering surface to it "
        "and the water appears full of stock. Short grass "
        "surrounding this lake is plush and lively. It "
        "refuses to grow on the towering bedrock to the "
        "north which prevents any commute but southward. "
        "A clear view of the Westwood leads southwest "
        "back into the forest and an obvious path leads "
        "south to an area which is less woody.");

 SetAmbientLight(20);        
 SetClimate("temperate");
 SetExits( ([
  "south" : RUINS_ROOMS "outside2",
        ]) );
 SetInventory( ([ 
            RUINS_OBJ "lake" : 1,
          ]) );
 SetListen("default", "The above waterfall gushes loudly "
                     "against the lake surface without rest." );
 SetSmell("default", "Clean thin air swirls about this entire lake.");

 SetItems( ([ 
    ({ "forest","southwest" }) : "The pine tree dominated forest "
                                 "leads southwest away from this "
                                 "lake. It looks of normal appearance "
                                 "complete with grasslands and bushes.",
     "waterfall" : "The recognizable waterfall source leads from "
                   "towering bedrock into the lake below. The height "
                   "of the waters descent makes its appearance known.",
     "surface" : "The surface of the lake shimmers in natural light. "
                 "It is calm and absorbs the constant agitation from "
                 "the waterfall.",
     "stock" : "Fish inside the lake itself look plentiful in the "
               "water. They seem alert and scatter quickly to disturbance. "
               "They vary in size but nothing appears to be large game.",
     "grass" : "The plush grass blankets the shore from the lake and "
               "stretches south back into the forest. It has small blades "
               "and rests free of weeds displaying its green colour.",
     "bedrock" : "The rockface to the north is jagged and weathered from "
                 "onslaught of the sheer force of water falling above. It "
                 "is made of very dense brown rock which would not yield "
                 "any wealth.",
     "structure" : "A structure appears off in the distance to the south. "
                   "From this distance it appears to be ancient ruins.",
     "ruins" : "The ruins to the south are too far to clarify in depth. "
               "A square structure with vines and age sit near a green "
               "moat.",
     "moat" : "A moat surrounds the outside of some ruins to the south.",
     "area" : "A less than normal woody area of the west wood is to the "
              "southern direction. A structure can be seen off in the far "
              "distance.",
     "rockface" : "The rockface is jagged and would prove difficult to "
                  "mine for profit. It towers over this scenery quite "
                  "noticeably.",
     "trees" : "Pine trees litter the Westwood in the forest.",
     "grasslands" : "A grassy field sparce with generic Westwood trees "
                    "can be seen to the south. Bushes litter the ground, "
                    "some even block an old structure to the south out "
                    "of view.",
     "bushes" : "The bushes in the south provide cover for the "
                "Westwood creatures. They vary in size and provide "
                "decent shade with their bushy leaves.",
     "water" : "The water is crystal clear and free of murky sediment "
               "despite all the activity from the waterfall. It is full "
               "of life, schools of fish banter about in a lazy fashion. "
               "It is not very deep, a normal sized human could wade "
               "through easily.",
     "sand" : "The sand bordering the lake is a soft white colour "
              "with small grains. Contrary to normal sand environments, "
              "it is contained and the grass keeps it in place.",
     "leaves" : "It is too far to inspect the leaves on the bushes "
                "to the south.",
     "path" : "A used pathway juts south into the grasslands.",                

    ]) );
 SetItemAdjectives( ([
    "trees" : ({ "pine" }),
    "lake" : ({ "crystal","clear","shimmering" }),
    "rockface" : ({ "giant","towering" }),
    "forest" : ({ "view","clear","westwood"}),
  ]) );
//Fish Stuffs 
 SetChance(25);
 SetMaxFishing(15);
 SetSpeed(5);
 SetFish( ([
         STD_FISH "mackerel" : 40,
         STD_FISH "trout" : 80,
         STD_FISH "guppy" : 80,
     ]) );
 SetEnters( ([
  "waterfall" : RUINS_ROOMS "cave01",
 ]) );
}

void heart_beat() {
  string fire;
  ::heart_beat();
  switch(random(5)) {
    case 0:
      fire = "The loud waterfall crashes against the lake blowing mist everywhere.";
    break;
    case 1:
      fire = "Light gusts of wind sway the trees and grass, almost like a dance.";
    break;
    case 2:
      fire = "Birds from the Westwood chirp a soft overtone.";
    break;
    case 3:
      fire = "Small ripples from the lake creep up along the shore, then recede.";
    break;
    case 4:
      fire = "The noise from the powerful waterfall envelopes this place.";
    break;
   }
  eventPrint(fire);
}
