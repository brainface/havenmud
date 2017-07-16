#include <lib.h>
inherit LIB_NPC;
#include "farm.h"
 
static void create() {
   npc::create();
   SetKeyName("adult pig");
   SetShort("an adult pig");
   SetId( ({ "adult pig","pig" }) );
   SetLong("The pig is muddy and dirty.");
   SetRace("pig");
   SetClass("valkyr");
   SetLevel(5);
   SetGender("female");
}
 
eventDie(object killer) {
   object item;
   item = new( F_OBJ + "/tail_la");
   item->eventMove(this_object());
   npc::eventDie(killer);
}