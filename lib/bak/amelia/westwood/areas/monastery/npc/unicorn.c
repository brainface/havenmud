#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

static void create() {
   npc::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("young unicorn");
   SetShort("a young unicorn");
   SetId( ({ "unicorn" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("The unicorn has big, sad eyes that speak of how his "
           "mother was killed and he wandered, sick, until taken "
           "in to this garden.  He is healthy and strong, now, but "
           "still young and limber.");
   SetRace("unicorn");
   SetGender("male");
   SetClass("animal");
   SetLevel(50);
   SetMorality(400);
}

void eventDie(object killer) {
   object horn;
   horn = new(M_OBJ + "horn");
   horn->eventMove(this_object());
   npc::eventDie(killer);
}
