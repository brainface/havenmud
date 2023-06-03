// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
/*SetLong("Entering the throne, one is surrounded in the enviroment "
     "of royalty.  The floors are all covered in an expensive "
     "looking carpet and the walls have murals painted on every "
     "foot.  On the east wall of the room, there is a step up "
     "floor that has a large wooden throne sitting on it.  There "
     "are pillars spread out in regular intervals between the "
     "entry and the throne.");
*/

#include <lib.h>
#include "../castle.h" 
        
inherit LIB_ROOM;       
         
string CurtainSearch();

static void create() {
::create();
SetShort("a forgotten throne room");
SetLong("Long tapestries drape the northwestern and southwestern "
        "walls in this old throne room. A raised platform similar "
        "to a large step has been raised and a wooden throne "
        "has been placed on it. The ground has numerous leaves "
        "and twigs which have found its way here. Large curtains "
        "have been hung across the north wall to the "
        "south wall clockwise. Six pillars from the western entrance "
        "align themselves to the eastern throne.");
  SetObviousExits("west");
  SetExits( ([
        "west" : RUINS_ROOMS "center",
        ]) );
  SetInventory( ([ 
            RUINS_NPC "ghostking" : 1,
              ]) );
SetListen("default","A soft hum can be heard.");
SetSmell("default","It smells of moldy carpet and rotten wood.");
SetClimate("indoors");
SetAmbientLight(10);
SetItems( ([ 
    ({ "room","throne room" }) : (: GetLong :),
    ({ "ground","floor" }) : "Along the surface of the ground "
        "some twigs and leaves can be seen that have been dragged "
        "in from the outside. A throne rests on it to the east and "
        "the floor itself is barren with no welcoming decor.",
    ({ "chair","throne" }) : "The throne on the platform is "
        "barely functional. It sits in pieces with some wood "
        "chopped off of it. It resides in shambles.",
    ({ "curtains","large curtains" }) : "Large red curtains "
        "cover some of the stone walls. They stand out and "
        "look recently disturbed.",
    ({ "twigs","leaves" }) : "Some twigs and leaves have been "
        "dragged into this section of the ruins. They litter "
        "the ground. Some have dried up, resting here a long time.",
     "curtain" : "The curtain is made of a flexible red velvet.",
     "tapestries" : "It is a painting of the West Wood fauna. It "
                    "doesnt appear to be of any quality other than "
                    "sentimental to whom inhabited these ruins.",
     "tapestry" : "It is a painting of a section of the West "
                  "Wood forest. Judging from the scenery it "
                  "appears to be somewhere close, near a "
                  "waterfall.",
     "ceiling" : "The ceiling is flat and composed of stone. Some "
                 "pillars along the mid west of the room support "
                 "the ceiling.",
     "walls" : "The walls have been made of square cut stones. Along "
               "the north wall to the eastern wall, one large curtain "
               "hangs.",
     "wall" : "The wall is covered with a curtain along the "
              "east side and the west side is barren. It is made "
              "of square cut stones.",
     "pillars" : "They line themselves directly to the raised "
                 "platform. There is six of them and they have "
                 "been placed neatly spaced apart for a more "
                 "direct view to the throne.",
     "pillar" : "The pillar is actually an untouched natural "
                "wooden log, sealed from the ceiling to the floor.",
     "stone" : "The stone is yellowed from age and seems somewhat "
               "porous. It has been cut into a square cut block and "
               "sealed to the others with a bond.",
     "stones" : "Visibly, the stones create the square throne "
                "room. The curtain blocks the view of some stones along "
                "the walls.",
     "entrance" : "The western entrance is a doorway which leads "
                  "into a large hallway.",
    ]) );
SetItemAdjectives( ([
    "tapestries" : ({ "northwestern","southwestern" }),
    "tapestry" : ({ "northwestern","southwestern" }),
    "curtains" : ({ "large" }),
    "stones" : ({ "yellow" }),
    "entrance" : ({ "western" }),
  ]) );
  SetSearch( ([
             "curtains"   : (: CurtainSearch :),
             "curtain"    : (: CurtainSearch :),
             ]) );
}
//Search one item, reveal TWO exits.
  string CurtainSearch() {
  if (GetExit("north") && GetExit("south")) {
    return "The curtains have already been pulled back displaying "+
           "the hidden chambers.";
  }
  AddExit("north", RUINS_ROOMS + "wizard");
  AddExit("south", RUINS_ROOMS + "treasure");
  SetObviousExits("north, west, south");
  return "The large red curtain reveals two hidden chambers!";
  }
