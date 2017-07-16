#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("speedy hummingbird");
   SetShort("a speedy hummingbird");
   SetId( ({ "hummingbird","bird" }) );
   SetAdjectives( ({ "speedy","small" }) );
   SetLong("The small bird zips around with no end to its energy.  "
           "He has a long sharp beak.");
   SetRace("bird");
   SetGender("male");
   SetClass("animal");
   SetLevel(2);
   
   AddCaffeine(30);
}

void eventDie(object killer) {
   object item;
   item = new(JD_OBJ + "/feather_hum");
   item->eventMove(this_object());
   npc::eventDie(killer);
}


/* Approved by Zaxan on Sat Jan 17 02:20:30 1998. */
