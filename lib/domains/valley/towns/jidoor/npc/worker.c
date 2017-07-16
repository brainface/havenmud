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
   SetId( ({ "worker","jidoor_npc" }) );
   SetAdjectives( ({ "jidoor", "construction" }) );
   SetShort("a Jidoor construction worker");
   SetLong("This construction worker seems to be working "
           "on a building in the city of Jidoor. He looks "
           "somewhat strong.");
   SetRace("sprite");
   SetClass("rogue");
   SetLevel(7);
   SetGender("male");
   SetMorality(5);
   
   SetCurrency("rupies",random(50)+20);
}
