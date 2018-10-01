#include <lib.h>
inherit LIB_NPC;
#include "../gorge.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("partridge");
   SetShort("a gray partridge");
   SetId( ({ "partridge","bird" }) );
   SetAdjectives( ({ "gray" }) );
   SetLong("Gray feathers with black stripes cover the partridge. "
           "The bird cocks its head to the side to examine you.");
   SetRace("bird");
   SetGender("female");
   SetClass("animal");
   SetLevel(2);
   
}

void eventDie(object killer) {
   object item;
   item = new(GORGE_OBJ + "/feather_partridge");
   item->eventMove(this_object());
   npc::eventDie(killer);
}
