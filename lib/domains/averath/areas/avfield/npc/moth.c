#include <lib.h>
#include "../avb.h"

inherit LIB_SENTIENT;


static void create() {
   sentient::create();
   SetProperty("avb",1);
   SetKeyName("moth");
   SetShort("a black moth");
   SetId( ({ "moth" }) );
   SetAdjectives( ({ "black" }) );
   SetLong("The black moth has two pair of partly decayed wings "
           "on its back that flap together simultaneously. The "
           "wings have large black vines scattered throughout them, "
           "It has two antennae on its head that are pointed "
           "at the tips. Its body though rather large is quite "
           "slender and very slimey. ");
   SetRace("moth",1);
   SetGender("female");
   SetClass("animal");
   SetLevel(35);
   SetStat("durability",40,3);
   SetStat("charisma",75,1);
   SetStat("intelligence",2,3);
   SetStat("luck",75,1);
   SetStat("agility",60,1);
   SetStat("wisdom",1,5);
   SetStat("strength",25,3);
   SetStat("coordination",60,2);
   AddLimb("torso",0,1,({ }) );
   AddLimb("head","torso",1,({ }) );
   AddLimb("left feeler","head",4,({ }) );
   AddLimb("right feeler","head",4,({ }) );
   AddLimb("first left wing","torso",3,({ }) );
   AddLimb("first right wing","torso",3,({ }) );
   AddLimb("second left wing","torso",3,({ }) );
   AddLimb("second right wing","torso",3,({ }) );
}

void eventDie(object killer) {
   object item;
   item = new(AVB_OBJ + "/wing");
   item->eventMove(this_object());
   sentient::eventDie();
}
