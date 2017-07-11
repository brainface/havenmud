#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("large wasp");
   SetShort("a large wasp");
   SetId( ({ "wasp" }) );
   SetAdjectives( ({ "large" }) );
   SetLong("The wasp is a large insect.  He has the ugly "
           "look of something that would like to sting others.");
   SetClass("animal");
   SetGender("male");
   SetLevel(2);
   SetRace("insect");
   AddLimb("right wing","torso",5,({ }) );
   AddLimb("left wing","torso",5,({ }) );
}

int eventDie(object agent) {
  object needle;

  needle = new("/domains/valley/areas/canyon/obj/needle");
  needle->eventMove(this_object());
  return (npc::eventDie(agent));
}

/* Approved by Zaxan on Sat Jan 17 02:28:48 1998. */
