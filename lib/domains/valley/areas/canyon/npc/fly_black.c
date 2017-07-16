#include <lib.h>
inherit LIB_NPC;

#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("black fly");
   SetShort("a black fly");
   SetId( ({ "fly" }) );
   SetAdjectives( ({ "black" }) );
   SetLong("Some light glints off the back of the black fly.");
   SetGender("male");
   SetRace("insect");
   AddLimb("left wing","torso",5,({ }) );
   AddLimb("right wing","torso",5,({ }) );
   SetClass("animal");
   SetLevel(1);
}


/* Approved by Zaxan on Sat Jan 17 02:19:42 1998. */
