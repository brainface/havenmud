#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("pensive man");
   SetShort("a pensive man");
   SetMorality(-50);
   SetId( ({ "man","human" }) );
   SetAdjectives( ({ "pensive" }) );
   SetLong("The man looks around worriedly, hoping that the weather "
           "will be good enough to climb farther into the WestWood "
           "tomorrow.  He looks like he's in his late twenties, and "
           "has been hiking and climbing for a good deal of his "
           "life.  He has a couple scars on his face showing where "
           "he has made mistakes to learn from.");
   SetGender("male");
   SetRace("human");
   SetClass("ranger");
   SetClass("barbarian");
   SetLevel(34+random(3));
   SetCurrency("cuicui",5060);
   SetCurrency("imperials",100);
   SetCurrency("nuggets",32);
   SetInventory( ([
                    H_OBJ + "knuckles" : "wear knuckles on left hand",
               ]) );
}
