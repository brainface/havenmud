#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("quiet man");
   SetShort("a quiet man");
   SetMorality(-75);
   SetId( ({ "man","human","male" }) );
   SetAdjectives( ({ "quiet","male","human" }) );
   SetLong("The human male stares silently into nothing, brooding "
           "over the period of time he and the rest of his climbing "
           "buddies have had to wait on the weather.  He is probably "
           "around thirty-five years old, and is missing his "
           "right hand.");
   SetRace("human");
   RemoveLimb("right hand",0);
   SetGender("male");
   SetClass("ranger");
   SetClass("barbarian");
   SetLevel(30+random(4));
   SetInventory( ([
                   H_OBJ + "kit" : 2,
              ]) );
}
