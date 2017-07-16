#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("cow");
   SetShort("a bored cow");
   SetId( ({ "bored cow","cow" }) );
   SetLong("The cow looks around with the dullest expression of "
           "stupidity.");
   SetRace("cow");
   SetClass("valkyr");
   SetLevel(4);
   SetGender("female");
}

eventDie(object killer) {
   object item;

   item = new(F_OBJ + "/bell");
   item->eventMove(this_object());
   npc::eventDie(killer);
}