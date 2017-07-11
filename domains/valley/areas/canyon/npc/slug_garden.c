#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("garden slug");
   SetShort("a garden slug");
   SetId( ({ "slug" }) );
   SetAdjectives( ({ "garden" }) );
   SetLong("The garden slug is a plain, slimy thing with little "
           "purpose but to slime up plants and crawl about.");
   SetRace("slug");
   SetGender("male");
   SetClass("animal");
   SetLevel(1);
}

void eventDie(object killer) {
   object item;
   item = new(JD_OBJ + "/shell");
   item->eventMove(this_object());
   npc::eventDie(killer);
}


/* Approved by Zaxan on Sat Jan 17 02:25:06 1998. */
