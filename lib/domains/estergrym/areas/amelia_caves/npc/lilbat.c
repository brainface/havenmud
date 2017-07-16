// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("small bat");
   SetId( ({ "bat" }) );
   SetAdjectives( ({ "small","little","dark","worried","anxious" }) );
   SetShort("a small bat");
   SetLong(
     "The little bat is dark in color, with a worried look "
     "to it, as if it is anxious about life in general."
   );
   SetRace("bat");
   SetClass("animal"); 
   SetLevel(1);
   
   SetGender("male");
}
 
 
void eventDie(object killer) {
    object item;
  item = new( C_OBJ + "sbatwing");
  item->eventMove(this_object());
  npc::eventDie(killer);
}
