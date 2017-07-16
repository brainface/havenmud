#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("caterpillar");
   SetShort("a multi-colored caterpillar");
   SetId( ({ "caterpillar" }) );
   SetAdjectives( ({ "multi-colored","fuzzy" }) );
   SetLong("This caterpillar is still young and quite fuzzy.");
   SetRace("caterpillar",1);
   SetGender("female");
   SetClass("animal");
   SetLevel(2);
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
