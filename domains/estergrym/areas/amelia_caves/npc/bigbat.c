// Amelia@Haven
#include <lib.h>
inherit LIB_NPC;
inherit LIB_LISTEN;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("bat");
   SetId( ({ "bat" }) );
   SetAdjectives( ({ "large" }) );
   SetShort("a large bat");
   SetLong(
     "Hanging serenely from the ceiling, the large bat makes "
     "strange squeaking noises around the room."
   );
   SetRace("bat");
   SetGender("male");
   SetClass("animal");
   SetLevel(3);
 
   SetListen("Squeaking noises come from the bat, reminescent of "
             "mouse and othe small rodent noises.");
}
 
 
void eventDie(object killer) {
    object item;
  item = new( C_OBJ + "batwing");
  item->eventMove(this_object());
  npc::eventDie(killer);
}

string GetListen(string str) {
   return listen::GetListen(str);
}
