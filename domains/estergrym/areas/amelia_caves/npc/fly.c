
// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("fruit fly");
   SetId( ({ "fly" }) );
   SetAdjectives( ({ "large","fruit","fragile" }) );
   SetShort("a large fruit fly");
   SetLong(
     "The fly is large, compared to most fruit flies, but is "
     "only about 4 inches long, and still seems just as fragile "
     "as the ordinary ones."
   );
   SetRace("insect");
   SetClass("animal");
   SetLevel(1);
   
}
 
 
void eventDie(object killer) {
    object item;
  item = new( C_OBJ + "wingf");
  item->eventMove(this_object());
  npc::eventDie(killer);
}
