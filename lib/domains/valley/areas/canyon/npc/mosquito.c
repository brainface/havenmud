#include <lib.h>
inherit LIB_SENTIENT;
#include "../jidnewbi.h"

static void create() {
   sentient::create();
   SetProperty("jidnewbinoleave",1);
   SetWander(24);
   SetKeyName("buzzing mosquito");
   SetShort("a buzzing mosquito");
   SetId( ({ "mosquito" }) );
   SetAdjectives( ({ "buzzing" }) );
   SetLong("The mosquito has the basic winged and many legged structure "
           "of all flying insects like him.");
   SetRace("insect");
   SetGender("male");
   AddLimb("right wing","torso",5,({ }) );
   AddLimb("left wing","torso",5,({ }) );
   SetClass("animal");
   SetLevel(1);
}


/* Approved by Zaxan on Sat Jan 17 02:23:30 1998. */
