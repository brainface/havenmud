// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("shivering mouse");
   SetId( ({ "mouse" }) );
   SetAdjectives( ({ "shivering","uncomfortable","wet","lost" }) );
   SetShort("a shivering mouse");
   SetLong(
     "Shivering violently, the little mouse looks terribly "
     "uncomfortable and wet, as well as rather lost."
   );
   SetRace("rodent");
   SetClass("animal"); 
   SetLevel(1);
   SetGender("male");
}
 
 
void eventDie(object killer) {
    object item;
  item = new( C_OBJ + "stuft");
  item->eventMove(this_object());
  npc::eventDie(killer);
}
