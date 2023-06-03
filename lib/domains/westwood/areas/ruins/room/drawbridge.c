// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
//  Urien@Haven 12.7.12
//  Made this room actually work the way it was intended.
//  Oldcode made it broken and unusable. Now its magically 
//  sealed or opened, dependant on the time of day. 
//   Copypasta from Xandria gate but with no keeper.

#include <lib.h> 
#include "../castle.h"          

#define WESTWOOD "/domains/westwood/virtual/westwood/"       

inherit LIB_ROOM;        

int PreExit();
 
static void create() 
{
::create();

SetShort("an ancient drawbridge");
SetLong("A thick deep moat surrounds some ancient ruins "
        "to the east. It seems the drawbridge is the primary "
        "entrance for the structure. The fauna "
        "surrounding the ruins appears overgrown and wild. "
        "Large coniferous trees thicken to the west and "
        "south leaving an open path north to a grassland. "
        "The ruins appear very old but sturdy, as "
        "if survived by many years of weathering.");
SetListen("default", "Birds chirping can be heard in the "
                     "Westwood here.");
SetSmell("default", "The moat reaks of stale water and "
                    "neglect.");
SetItems( ([ 
    ({ "drawbridge","entrance" }) : "The drawbridge "
           "which is supported by chains and pulleys "
           "looks of unusual wood. The entrance itself "
           "is made in the form of an arch from the "
           "yellowed bricks.",
    ({ "west","south","westwood" }) : "Westwood trees "
           "thicken to the south and west in regular "
           "fashion. It revels in complete mystery the "
           "content of the insides.",
    ({ "east","castle" }) : "The castle sits in ruin. Yellow "
              "bricks form an arch to the east which contain "
              "a drawbridge with chains and pulleys. Grass "
              "forms around the structure wildly as if not "
              "disturbed in ages.",
    ({ "grass","ground" }) : "The ground is made of a tall "
              "green grass. Some sporadic WestWood trees "
              "have been growing here that provide a comfortable "
              "shade against natural lighting, but not enough "
              "to kill off the fauna below.",
     "wall" : "A large wall makes up the western wall of "
              "this structure. It is made of yellow bricks.",
     "bricks" : "The porous bricks have been built a ways "
                "to prevent intense siege, big and tight. They "
                "form an arch to the east through the wall.",
     "moat" : "The moat sits motionless near the drawbridge. "
              "The pooled green water sits motionless and runs "
              "from the north to the south dressing the ruins "
              "accordingly.",
     "ruins" : "Some old ruins rest to the east completely "
               "made of yellow brick. An arch can be seen "
               "along the entrance.",
     "structure" : "The structure itself seems solid for "
                   "sentient beings to house themselves in "
                   "comfortably. The moat is deep enough that "
                   "it does not cause any integrity damage.",
     "fauna" : "Long grass has grown wild along the "
               "structure of the castle with yellow "
               "bricks. Even dead grass from past "
               "seasons still lay in waste.",
     "trees" : "Coniferous trees dominate the forest "
               "of the WestWood. They have grown from "
               "ages past out of the ground through the "
               "grass. They thicken south and southwest "
               "from here.",
     "tree" : "No matter the tree seen they are all "
              "similar. They are pine trees which "
              "seem to have started growing ages "
              "ago. They overcast the grass here and "
              "block out a good portion of natural "
              "lighting from above the Westwood.",
     "wall" : "The castle wall to the east is made of "
              "yellow looking brick. Its structure is "
              "still solid and it holds the drawbridge "
              "with chains and pulleys. Some weathered "
              "symbols have been engraved in the stone "
              "in ages past.",
     "symbols" : "The old symbols are carved into the "
                 "shapes of a triangle and a circle. "
                 "They are etched in the wall above "
                 "the drawbridge.",
     "triangle" : "The triangle points up with the base "
                  "flat, parallel to the ground here.",
     "circle" : "The circle etched into the wall is "
                "below the flat triangle. It has some "
                "settled water along the ridges.",
     "shapes" : "Shapes of a triangle and circle are "
                "displayed above the drawbridge arch.",
     "arch" : "The arch houses the drawbridge when it "
              "is up. It is made of the same yellow "
              "stone as the walls. Some symbols "
              "have been etched above the joined arch "
              "that look somewhat dulled by weather.",
     "brick" : "The brick is porous and it has been "
               "cemented to other bricks. Some litter "
               "the ground but weigh too heavy to look "
               "underneath.",
    ]) );
SetItemAdjectives( ([
    "ruins" : ({ "ancient" }),
    "moat" : ({ "deep","thick" }),
    "fauna" : ({ "overgrown" }),
    "trees" : ({ "coniferous","pine" }),
    "tree" : ({ "coniferous","pine" }),
    "wall" : ({ "white","ivory" }),
    "grass" : ({ "long","dead","green" }),
  ]) );
SetExits( ([
        "north" : RUINS_ROOMS + "outside2",   
        "west"     : WESTWOOD + "30,30",
        ]) );
SetClimate("temperate");
AddExit("east", RUINS_ROOMS "entry", (:PreExit:));
}

int PreExit() {
  object who = this_player();
  if (!query_night()) { return 1; }
  send_messages( ({ "bump" }),
    "$agent_name $agent_verb into the closed wooden drawbridge.",
    who, 0, this_object());
  return 0;
}

string GetLong() {
  string LLL = ::GetLong();
  if (query_night()) {
    LLL += " The drawbridge is magically sealed at night.";
  }
  else LLL += " The drawbridge remains open during the daylight.";
  return LLL;
}
