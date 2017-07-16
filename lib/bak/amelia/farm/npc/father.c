#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("father");
   SetShort("a farmer father");
   SetId( ({ "farmer father","father","farmer" }) );
   SetLong("The farmer has a rough face and strong hangs, and he looks "
           "as if he is not interested in visitors.");
   SetRace("human");
   SetClass("fighter");
   SetLevel(15);
   SetGender("male");
   SetInventory( ([
                    "/std/weapon/hack/meat_hook" : "wield hook",
               ]) );
   SetCurrency("imperials",300+random(100));
}