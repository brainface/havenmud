// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"
 
static void create() {
   npc::create();
   SetKeyName("tree");
   SetId( ({ "enchanted tree","tree","normal enchated tree","normal tree" }) );
   SetShort("a small enchanted tree");
   SetLong("One red eye glares at the world from the trunk of the enchanted "
           "tree, and greenish-brown leaves rustle on the branches.");
   SetRace("tree");
   SetClass("animal");
   SetLevel(random(2)+1);
   
   SetDie("A branch breaks off the tree.");
   SetCorpseItems( ([ B_OBJ + "/brancha" : 1, ]) );
   SetMorality(-75);
}