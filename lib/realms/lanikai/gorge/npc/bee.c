#include <lib.h>
inherit LIB_NPC;
#include "../gorge.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("large bee");
   SetShort("a large bee");
   SetId( ({ "bee" }) );
   SetAdjectives( ({ "large" }) );
   SetLong("This bee is quite large and looks like he may attack "
           "you if you anger him.");
   SetClass("animal");
   SetGender("male");
   SetLevel(2);
   SetRace("insect");
   AddLimb("right wing","torso",5,({ }) );
   AddLimb("left wing","torso",5,({ }) );
}

int eventDie(object agent) {
  object stinger;

  stinger = new("/domains/namatar/areas/gorge/obj/stinger");
  stinger->eventMove(this_object());
  return (npc::eventDie(agent));
}
