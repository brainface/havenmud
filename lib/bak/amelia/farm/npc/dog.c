#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("dog");
   SetShort("a large dog");
   SetId( ({ "large dog","dog" }) );
   SetLong("The dog is bigger than most dogs, and looks a little lazy.  "
           "He has beautiful long fur, however.");
   SetRace("dog");
   SetClass("valkyr");
   SetLevel(6);
   SetGender("male");
   SetDie("You slice of one of his ears as he dies.");
}

eventDie(object killer) {
   object item;

   item = new( F_OBJ + "/dogear");
   item->eventMove(this_object());
   npc::eventDie(killer);
}