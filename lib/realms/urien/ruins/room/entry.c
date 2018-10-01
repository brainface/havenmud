// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12 
/*SetLong("This is the entry way into a very impressive looking "
  "castle.  The castle walls are a pure white color with unused "
  "torch mounts and have small arrow slits scattered along the "
  "entire length.  The entry into the castle is guarded with a "
  "large portcullis on both sides and a small hole in the roof "
  "appears to be a means for someone to stop attackers.  To the "
  "east if the center room into the castle and to the west if "
  "the exit.");
*/

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h" 

int PreExit();         
 
static void create() {
::create();
SetShort("entrance of the ancient ruins");
SetLong("The interior of the ruins radiates a time when this "
        "castle was full of life. This narrow hallway leads "
        "east from the drawbridge access through a large "
        "archway. The walls have been heavily aged and the "
        "structure appears solid. A poorly maintained "
        "portcullis rests inside the tall archway. Leaves from "
        "the Westwood have blown in creating piles of "
        "slimy hazards to unweary travellers.");
SetExits( ([
  "east" : RUINS_ROOMS "center",
]) );
AddExit("west", RUINS_ROOMS "drawbridge", (:PreExit:));

SetListen("default","The torch crackles briskly.");
SetSmell("default","It smells of dust and old mildew.");
SetClimate("indoors");
SetItems( ([ 
    ({ "ruins","castle" }) : (: GetLong :),
    ({ "drawbridge","access" }) : "The drawbridge access "
       "upright would create a seal that would prevent "
       "leaving through traditional means. It is long, "
       "flat and unclimbable.", //That's what she said
    ({ "ground","floor" }) : "The ground inside these ruins "
       "is small stones which have been cemented together. "
       "The floor itself is flat with occasional depressions "
       "along the surface. It is covered in pine leaves.",
    ({ "westwood","Westwood" }) : "The WestWood lies "
       "directly to the west out of the castle ruins.",
    ({ "entrance","archway" }) : "Aged castle walls from "
       "the inside and the outside of the ruins have been "
       "built together to form an entrance into this "
       "building. It has been built to accomodate the "
       "drawbridge and prevent any access to intruders.",
     "torch" : "Along the north wall, east of the "
       "portcullis a secured torch rests. It appears "
       "to burn magically providing waning light.",
     "interior" : "The interior is quite simple and "
       "drab. Any treasures which may have been here "
       "have long been looted. A portcullis divides "
       "the Westwood to the structure which rests "
       "directly next to a torch.",
     "walls" : "The walls are perfectly flat and lead "
       "east, deeper into the castle.",
     "wall" : "It is slightly pourous from age and it "
       "forms together creating a hallway. The wall "
       "seems to have lasted ages and all of them "
       "look sturdy.",
     "stone" : "Stone material is slightly yellow but "
       "would yield little to no value. Looking at them "
       "mining would make them brittle. The stone "
       "has all been cemented together some time ago.",
     "hallway" : "This hallway from the drawbridge leads "
       "east into the castle.",
     "portcullis" : "The portcullis remains untouched by "
       "an engineer in ages. It rests in rust however "
       "still functional due to its thickness. If this "
       "failed to uphold it would prove fatal with the "
       "spikes from the bottom of the gate.",
     "leaves" : "Pine leaves litter the entire hallway "
       "from the portcullis far into the hallway east.",
     "leaf" : "The pine leaf individually looks like "
       "a fanned paintbrush tip. It sits in its own "
       "decay and appears slimy.",
     "wood" : "It has been polished and appears "
       "functional. It seems have been used for "
       "a long time.",
     "drawbridge" : "The drawbridge is made of a thick "
       "polished wood, reinforced with bracers to keep "
       "them together. This would easily keep out hordes "
       "of enemies.",
     "gate" : "The portcullis gate is a standard mesh "
       "design of metal, with sharpened spikes on the "
       "bottom. It looks unpolished and worn from "
       "ages of use. The points have even flattened "
       "horizontally.",
//     "" : ".",
//     "" : ".",
//     "" : ".",
    ]) );
SetAmbientLight(5);
SetItemAdjectives( ([
    "hallway" : ({ "narrow","stone" }),
    "walls" : ({ "aged","ancient","castle","old" }),
    "leaf" : ({ "pine","Westwood","westwood" }),
    "leaves" : ({ "pine","WestWood","westwood" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
  ]) );
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
    LLL += " The portcullis is closed at night.";
  }
  else LLL += " The portcullis remains open during the daylight.";
  return LLL;
}
