#include <lib.h>
inherit LIB_SENTIENT;
#include "../gorge.h"

static void create() {
   sentient::create();
   SetKeyName("beautiful butterfly");
   SetShort("a beautiful butterfly");
   SetId( ({ "butterfly" }) );
   SetAdjectives( ({ "beautiful" }) );
   SetLong("The beautiful butterfly gracefully flaps her marvelous "
           "wings to try and stay afloat.");
   SetRace("butterfly",1);
   SetGender("female");
   SetClass("animal");
   SetLevel(1);
   SetStat("durability",2,5);
   SetStat("charisma",25,5);
   SetStat("intelligence",2,5);
   SetStat("luck",55,1);
   SetStat("agility",30,2);


   SetStat("wisdom",1,5);
   //SetStat("speed",50,1);
   SetStat("strength",1,5);
   SetStat("coordination",30,3);
   AddLimb("torso",0,1,({ }) );
   AddLimb("head","torso",1,({ }) );
   AddLimb("left feeler","head",4,({ }) );
   AddLimb("right feeler","head",4,({ }) );
   AddLimb("left wing","torso",3,({ }) );
   AddLimb("right wing","torso",3,({ }) );
 
}

void eventDie(object killer) {
   object item;
   item = new(GORGE_OBJ + "/wing_butterfly");
   item->eventMove(this_object());
   sentient::eventDie();
}
