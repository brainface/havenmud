// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
// Added Everything

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h"          
 
static void create() {
::create();
  SetShort("a former barracks");
  SetLong("This large section of the ancient ruins appears to have "
        "been formed to house numerous defenders. Stacks of "
        "furniture have been pushed to the northeast corner which "
        "rest broken and shattered. A hanging old tapestry "
        "has been placed on the north wall displaying some "
        "scenes of a prior battle. A clear walkway has "
        "been made that leads from the west to the south free "
        "of obstructions.");
  SetListen("default","The small room resonates in silence.");
  SetSmell("default","It smells of stagnate water.");
  SetExits( ([
  "west"  : RUINS_ROOMS "armoury",
  "south" : RUINS_ROOMS "center",
  ]) );
  SetClimate("indoors");
  SetItems( ([ 
    ({ "ruins","section","barracks","room" }) : (: GetLong :),
    ({ "furniture","northeast corner","corner" }) : "In the "
       "northeast corner, former decor and furniture rest in "
       "a pile. It seems it was lobbed in the corner rather "
       "carelessly and even added to the damage inflicted on "
       "the wood. Broken mattresses and beds lie in the pile "
       "as well, serving no purpose.",
    ({ "scene","battle" }) : "The battle scene has been painted "
    "showing countless known races of Kailie fighting against "
    "a giant red dragon.",
    ({ "obstructions","debris","junk" }) : "Junk has been "
       "thrown in the corner to further clear a path to each "
       "doorway. Broken chairs, furniture and beds all pile "
       "about stinking of wet muezzin.",
    ({ "ceiling","up" }) : "The ceiling is flat and seems secure "
       "despite age. It has been formed by yellow stones.",
    ({ "ground","floor" }) : "It is barely manageable to transit "
       "freely. Broken furniture rests all about, most of it "
       "in the northeastern corner.",
    ({ "doorways","doorway" }) : "The doorways have been framed "
       "to enhance this shoddy castle.",
     "walkway" : "A clear walkway can be made doorway to doorway "
       "and not much else. The walkway itself is created by the "
       "piles of furniture debris which lie everywhere.",
     "tapestry" : "The tapestry is made of paper and depicts "
       "a battle. It looks as if it was finger painted.",
     "north wall" : "The north wall is flat and has furniture "
       "stacked against the surface of it. It looks made of the "
       "same stone as this entire section of ruins.",
     "beds" : "A few beds can be seen in the pile of junk "
       "in the corner. They seem beyond use.",
     "bed" : "The bed is made of a long burlap sack, which "
       "is in complete shreds. The framing is missing and "
       "there is stains all along the surface.",
     "mattress" : "The mattress looks stained and do not look "
       "as if it would be useful to anyone.",
     "mattresses" : "They rest in a pile with other furniture "
       "in the northeast corner.",
     "trunks" : "Battered trunks lie strewn about the room. "
       "They have been previously violated, none are functional.",
     "wood" : "The wood is oak and shows some impact along "
              "its surface from prior handling. It is "
              "split and cracked making the furniture "
              "unusable.",
     "southwest corner" : "In the corner another pile sits with "
       "unwanted wood scraps and broken furniture.",
     "corners" : "The corners of the room are filled with unwanted "
       "treasures from raiders or survivors. It is all useless junk.",
     "walls" : "The walls are made of yellow aged stone, that "
       "look incredibly sturdy. A tapestry hangs on the north "
       "wall faintly displaying a story.",
     "wall" : "The wall is made of yellow aged stone which "
       "is thick and strong.",
     "stones" : "Yellow stones rest atop each other to form "
       "the walls here. They are identically cut and placed "
       "offset to ensure a secure hold.",
     "stone" : "The stone is yellow from age and somewhat porous.",
    ]) );
  SetItemAdjectives( ([
    "furniture" : ({ "stacks of","stacks" }),
    "tapestry" : ({ "old" }),
    "wood" : ({ "wet","old","oak" }),
    "walls" : ({ "stone" }),
    "stone" : ({ "yellow" }),
  ]) );
}