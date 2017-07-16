#include <lib.h>
inherit LIB_NPC;
#include "farm.h"

static void create() {
   npc::create();
   SetKeyName("son");
   SetShort("a farmer son");
   SetId( ({ "farmer son","farmer","son" }) );
   SetLong("Shaggy peach fuzz covers the face of this boy, but he still "
           "has muscles to back himself up.");
   SetRace("human");
   SetGender("male");
   SetClass("valkyr");
   SetLevel(9);
   SetInventory( ([
                    F_OBJ + "/bknuckle" : "wield brass knuckles",
               ]) );
   SetCurrency("imperials",245);
}