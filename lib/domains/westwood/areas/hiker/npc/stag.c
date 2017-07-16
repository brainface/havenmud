#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("brown stag");
   SetShort("a brown stag");
   SetId( ({ "stag","deer","male" }) ); 
   SetAdjectives( ({ "brown" }) );
   SetLong("A nice set of antlers sits proudly on the stag's head.  "
           "He is young and strong.");
   SetGender("male");
   SetRace("deer");
   SetClass("animal");
   SetLevel(7+random(3));
   SetMeleeAttackString("antlers");
   SetMeleeDamageType(BLUNT);
}

void eventDie(object killer) {
   object dis;
   dis = new(H_OBJ + "antlers");
   dis->eventMove(this_object());
   ::eventDie(killer);
}
