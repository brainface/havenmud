#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("horse");
   SetShort("an adult horse");
   SetId( ({ "adult horse","adult","horse" }) );
   SetLong("The horse flicks her tail angrily at the bugs.");
   SetRace("horse");
   SetClass("valkyr");
   SetLevel(6);
   SetGender("female");
}

eventDie(object killer) {
   object item;

   item = new( F_OBJ + "/hoof_la");
   item->eventMove(this_object());
   npc::eventDie(killer);
}