#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("long centipede");
   SetShort("a long centipede");
   SetId( ({ "centipede" }) );
   SetAdjectives( ({ "long" }) );
   SetLong("The centipede is black with red fringes around his many "
           "legs and segments.");
   SetRace("centipede",1);
   SetGender("male");
   SetClass("animal");
   SetLevel(1);
   SetStat("durability",1,5);
   SetStat("charisma",1,5);
   SetStat("intelligence",1,5);
   SetStat("luck",43,1);
   SetStat("agility",31,2);
   SetStat("wisdom",1,5);
   //SetStat("speed",43,1);
   SetStat("strength",1,5);
   SetStat("coordination",21,3);
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


/* Approved by Zaxan on Sat Jan 17 02:29:36 1998. */
