#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("jay");
   SetShort("a blue jay");
   SetId( ({ "jay","bird" }) );
   SetAdjectives( ({ "blue" }) );
   SetLong("Dark blue and black feathers cover the blue jay in "
           "a majestic simplicity.");
   SetRace("bird");
   SetGender("female");
   SetClass("animal");
   SetLevel(1);
   
}

void eventDie(object killer) {
   object item;
   item = new(JD_OBJ + "/feather_jay");
   item->eventMove(this_object());
   npc::eventDie(killer);
}


/* Approved by Zaxan on Sat Jan 17 02:21:01 1998. */
