// amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("timid mouse");
   SetId( ({ "rodent","mouse" }) );
   SetAdjectives( ({ "slightly dry","half-dry","rather wet","wet",
                     "half-wet","miserable" }) );
   SetShort("a half-dry mouse");
   SetLong(
     "The mouse is slightly dry, but rather wet too.  Even though "
     "he's part of the way to complete dry, he doesn't seem to "
     "care:  He looks just as miserable as if he was totally "
     "dry.  It must not matter to a mouse, if he is just "
     "half-wet, or if he is actually all the way wet."
   );
   SetRace("rodent");
   SetClass("animal");
   SetLevel(1);
  
   SetGender("male");
}
 
 
void eventDie(object killer) {
    object item;
  item = new( C_OBJ + "htuft");
  item->eventMove(this_object());
  npc::eventDie(killer);
}
