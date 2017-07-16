#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("daughter");
   SetShort("a farmer daughter");
   SetId( ({ "farmer daughter","farmer","daughter" }) );
   SetLong("This sweet girl of about 10 years old wears a pretty "
           "pink ribbon in her hair and a pretty pink dress on her body.");
   SetRace("human");
   SetGender("female");
   SetClass("evoker");
   SetLevel(7);
   SetInventory( ([
                    F_OBJ + "/rake" : "wield rake",
               ]) );
   SetCurrency("imperials",100);
}