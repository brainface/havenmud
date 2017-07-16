#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("piglet");
   SetShort("an little piglet");
   SetId( ({ "little piglet","piglet","pig" }) );
   SetLong("The piglet is muddy and dirty.");
   SetRace("pig");
   SetClass("valkyr");
   SetLevel(2);
   SetGender("male");
}

eventDie(object killer) {
   object item;
   item = new( F_OBJ + "/tail_sm");
   item->eventMove(this_object());
   npc::eventDie(killer);
}