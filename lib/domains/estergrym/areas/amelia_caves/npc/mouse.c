// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("timid mouse");
   SetId( ({ "timid mouse","mouse" }) );
   SetAdjectives( ({ "timid","worried","trembling","shivering" }) );
   SetShort("a timid mouse");
   SetLong(
     "If a mouse could have worry lines, this one probably would.  "
     "He trembles and shivers, timid about the entire concept of "
     "living, especially in a dark cave with things like spiders "
     "and fish."
   );
   SetRace("rodent");
   SetClass("animal");
   SetLevel(1);
  
   SetGender("male");
}
 
 
void eventDie(object killer) {
    object item;
  item = new( C_OBJ + "tuft");
  item->eventMove(this_object());
  npc::eventDie(killer);
}
