#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("shaggy pony");
   SetShort("a shaggy pony");
   SetId( ({ "pony" }) );
   SetAdjectives( ({ "shaggy" }) );
   SetLong("Long, shaggy hair covers up the pony, with extra amounts "
           "around his head and hooves.");
   SetGender("male");
   SetRace("horse");
   SetClass("animal");
   SetLevel(2);
}

void eventDie(object killer) {
   object item;
   item = new(JD_OBJ + "/mane");
   item->eventMove(this_object());
   npc::eventDie(killer);
}


/* Approved by Zaxan on Sat Jan 17 02:25:46 1998. */
