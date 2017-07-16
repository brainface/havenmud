// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"

static void create() {
   npc::create();
   SetKeyName("tree");
   SetId( ({ "enchanted tree","tree","tall tree","tall enchanted tree" }) );
   SetShort("a tall enchanted tree");
   SetLong("One red eye glares at the world from the trunk of the enchanted "
           "tree, and silver-gold leaves rustle on the branches.");
   
   SetRace("tree");
   SetClass("animal");
   SetLevel(random(2)+3);
   
   SetDie("A branch breaks off the tree.");
   SetInventory( ([
                    B_OBJ + "/sleaf" : random(3)+1,
                    B_OBJ + "/gleaf" : random(3),
               ]) );
   SetMorality(-100);
   SetCorpseItems( ([ B_OBJ + "/branchb" : 1 ]) );
}