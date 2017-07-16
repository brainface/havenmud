#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("small black spider");
   SetShort("a small black spider");
   SetId( ({ "spider" }) );
   SetAdjectives( ({ "small","black" }) );
   SetLong("The spider is small, and looks easily squishable.  She is "
           "of the general harmless woods variety.");
   SetRace("arachnid");
   SetGender("female");
   SetClass("animal");
   SetLevel(1);
}
