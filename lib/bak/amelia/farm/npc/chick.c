#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("chick");
   SetShort("an industrious chick");
   SetId( ({ "industrious chick","chick" }) );
   SetLong("The young chick flops around the yard, yellow fluffy feathers "
           "ruffled up.");
   SetRace("bird");
   SetClass("valkyr");
   SetLevel(2);
   SetGender("female");
   SetInventory( ([
                    F_OBJ + "/grain" : random(3)+1,
               ]) );
}
