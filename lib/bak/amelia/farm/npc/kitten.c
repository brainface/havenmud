#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("kitten");
   SetShort("a mewling kitten");
   SetId( ({ "mewling kitten","kitten" }) );
   SetLong("The kitten mewls for its mother and her milk.");
   SetRace("cat");
   SetClass("valkyr");
   SetLevel(1);
   SetGender("female");
}

eventDie(object killer) {
   object item;
   item = new( F_OBJ + "/fur_sm");
   item->eventMove(this_object());
   npc::eventDie(killer);
}