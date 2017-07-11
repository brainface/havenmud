#include <lib.h>
#include "../avb.h"

inherit LIB_NPC;

static void create() {
   npc::create();
   SetProperty("averath cave",1);
   SetKeyName("huge centipede");
   SetShort("a huge centipede");
   SetId( ({ "centipede" }) );
   SetAdjectives( ({ "huge" }) );
   SetLong("The huge centipede has a flattened body which divids "
           "into a head and a long body composed of segments. Its "
           "head has two very long antenne and two large pincers "
           "that form around the front of its face. Its body is "
           "covered in furry tan legs on each segment.");
   SetRace("centipede",1);
   SetGender("male");
   SetClass("animal");
   SetLevel(35);
   SetStat("durability",70,1);
   SetStat("charisma",1,5);
   SetStat("intelligence",1,3);
   SetStat("luck",75,1);
   SetStat("agility",70,1);
   SetStat("wisdom",1,5);
   SetStat("strength",30,3);
   SetStat("coordination",50,2);
   AddLimb("first segment",0,1,({ }) );
   AddLimb("head","first segment",1,({ }) );
   AddLimb("right feeler","head",4,({ }) );
   AddLimb("left feeler","head",4,({ }) );
   AddLimb("first right leg","first segment",5,({ }) );
   AddLimb("first left leg","first segment",5,({ }) );
   AddLimb("second segment","first segment",3,({ }) );
   AddLimb("second right leg","second segment",5,({ }) );
   AddLimb("second left leg","second segment",5,({ }) );
   AddLimb("third segment","second segment",3,({ }) );
   AddLimb("third right leg","third segment",5,({ }) );
   AddLimb("third left leg","third segment",5,({ }) );
   AddLimb("fourth segment","third segment",3,({ }) );
   AddLimb("fourth right leg","fourth segment",5,({ }) );
   AddLimb("fourth left leg","fourth segment",5,({ }) );
   AddLimb("fifth segment","fourth segment",3,({ }) );
   AddLimb("fifth right leg","fifth segment",5,({ }) );
   AddLimb("fifth left leg","fifth segment",5,({ }) );
   AddLimb("sixth segment","fifth segment",3,({ }) );
   AddLimb("sixth right leg","sixth segment",5,({ }) );
   AddLimb("sixth left leg","sixth segment",5,({ }) );
   AddLimb("seventh segment","sixth segment",3,({ }) );
   AddLimb("seventh right leg","seventh segment",5,({ }) );
   AddLimb("seventh left leg","seventh segment",5,({ }) );
}

