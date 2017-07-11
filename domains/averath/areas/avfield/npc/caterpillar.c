#include <lib.h>
#include "../avb.h"

inherit LIB_NPC;


static void create() {
   npc::create();
   SetProperty("averath cave",1);
   SetKeyName("hairy caterpillar");
   SetShort("a huge hairy caterpillar");
   SetId( ({ "caterpillar" }) );
   SetAdjectives( ({ "huge","hairy","furry" }) );
   SetLong("The huge caterpillar has three pairs of short, "
           "jointed legs on its first segment; in addition, it "
           "has unjointed, fleshy appendages on its second and "
           "third segments. The last two sets of legs are much "
           "larger then the first and end in clusters of tiny "
           "hooks that they use in certain situations. It also "
           "has a row of simple eyes on either side of the body "
           "so that it is always prepared. ");
   SetRace("caterpillar",1);
   SetGender("male");
   SetClass("animal");
   SetLevel(35);
   SetStat("durability",70,1);
   SetStat("charisma",1,3);
   SetStat("intelligence",1,5);
   SetStat("luck",65,1);
   SetStat("agility",70,1);
   SetStat("wisdom",1,5);
   SetStat("strength",50,2);
   SetStat("coordination",35,3);
   AddLimb("first segment",0,1,({ }) );
   AddLimb("head","first segment",1,({ }) );
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
}





