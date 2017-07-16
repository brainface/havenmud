#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("fat caterpillar");
   SetShort("a fat caterpillar");
   SetId( ({ "caterpillar" }) );
   SetAdjectives( ({ "fat","furry" }) );
   SetLong("The furry caterpillar is very fat and languid.");
   SetRace("caterpillar",1);
   SetGender("female");
   SetClass("animal");
   SetLevel(1);
   SetStat("durability",2,5);
   SetStat("charisma",5,5);
   SetStat("intelligence",1,5);
   SetStat("luck",55,1);
   SetStat("agility",25,2);
   SetStat("wisdom",1,5);
   //SetStat("speed",20,1);
   SetStat("strength",2,5);
   SetStat("coordination",17,3);
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


/* Approved by Zaxan on Sat Jan 17 02:30:02 1998. */
