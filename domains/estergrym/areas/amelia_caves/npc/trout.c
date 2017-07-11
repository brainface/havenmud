// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("eyeless trout");
   SetId( ({ "trout","eyeless trout","fish" }) );
   SetShort("an eyeless trout");
   SetLong(
     "The eyeless trout is small, no more than six inches in length.  "
     "Where its eyes should be, shapeless lumps now exist."
   );
   SetRace("fish");
   SetClass("animal");
   SetLevel(1);
   SetGender("male");
   
   SetDie("The oily fish beaches itself as it dies.");
}
 
 
void eventDie(object killer) {
  object item;
  item = new( C_OBJ + "oil");
  item->eventMove(this_object());
  npc::eventDie(killer);
}
