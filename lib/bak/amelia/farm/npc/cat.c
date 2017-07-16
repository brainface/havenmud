#include <lib.h>
inherit LIB_NPC;
#include "farm.h"
 
static void create() {
   npc::create();
   SetKeyName("cat");
   SetShort("a protective cat");
   SetId( ({ "protective cat","cat" }) );
   SetLong("The cat circles around pensively.");
   SetRace("cat");
   SetClass("valkyr");
   SetLevel(3);
   SetGender("female");
}
 
eventDie(object killer) {
   object item;
   item = new( F_OBJ + "/fur_la");
   item->eventMove(this_object());
   npc::eventDie(killer);
}