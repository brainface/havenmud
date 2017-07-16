// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"
 
static void create() {
   npc::create();
   SetProperty("enchforestnoleave",1);
   SetKeyName("tree");
   SetId( ({ "enchanted tree","tree","normal enchated tree","normal tree" }) );
   SetShort("a normal enchanted tree");
   SetLong("One red eye glares at the world from the trunk of the enchanted "
           "tree, and greenish-brown leaves rustle on the branches.");
   SetLevel(random(2)+1);
   SetClass("valkyr");
   SetRace("tree");
   SetDie("A branch breaks off the tree.");
   SetMorality(-75);
}
 
varargs int eventDie(object killer) {
   object item;
   item = new( B_OBJ + "/brancha");
   item->eventMove(this_object());
   npc::eventDie(killer);
}
