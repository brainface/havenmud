#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("chicken");
   SetShort("a lazy chicken");
   SetId( ({ "lazy chicken","chicken" }) );
   SetLong("The chicken pecks at the grain lazily.");
   SetRace("bird");
   SetClass("valkyr");
   SetLevel(2);
   SetGender("female");
   SetInventory( ([
                    F_OBJ + "/grain" : random(3)+4,
               ]) );
}