// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"

static void create() {
   npc::create();
   SetProperty("enchforestnoleave",1);
   SetKeyName("tree");
   SetId( ({ "enchanted tree","tree","tall tree","tall enchanted tree" }) );
   SetShort("a tall enchanted tree");
   SetLong("One red eye glares at the world from the trunk of the enchanted "
           "tree, and silver-gold leaves rustle on the branches.");
   SetLevel(random(2)+3);
   SetClass("valkyr");
   SetRace("tree");
   SetDie("A branch breaks off the tree.");
   SetInventory( ([
                    B_OBJ + "/sleaf" : random(3)+1,
                    B_OBJ + "/gleaf" : random(3),
               ]) );
   SetMorality(-100);
}

varargs int eventDie(object killer) {
   object item;
   item = new( B_OBJ + "/branchb");
   item->eventMove(this_object());
   npc::eventDie(killer);
}
