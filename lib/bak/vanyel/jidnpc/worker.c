//
// A Jidoor construction worker
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("worker");
   SetId( ({ "worker" }) );
   SetAdjectives( ({ "jidoor", "construction" }) );
   SetShort("a Jidoor construction worker");
   SetLong("This construction worker seems to be working "
           "on a building in the city of Jidoor. He looks "
           "somewhat strong.");
   SetLevel(7);
   SetGender("male");
   SetMorality(5);
   SetRace("sprite");
   SetClass("fighter");
   SetCurrency("rupies",random(250));
}
