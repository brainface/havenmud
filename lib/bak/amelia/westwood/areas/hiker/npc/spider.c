#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("dark arachnid");
   SetShort("a gigantic dark arachnid");
   SetId( ({ "arachnid","spider" }) );
   SetAdjectives( ({ "dark","gigantic" }) );
   SetLong("The giant arachnid is at least four feet high, with a "
           "large body to be supported by its thick legs.  Her fangs "
           "have the silent gleam on them that speaks of poison.");
   SetGender("female");
   SetRace("arachnid");
   SetClass("animal");
   SetLevel(16);
   SetMeleeAttackString("fangs");
   SetMeleeDamageType(POISON);
}

void eventDie(object killer) {
   object blah;
   blah = new(H_OBJ + "sac");
   blah->eventMove(this_object());
   ::eventDie(killer);
}
