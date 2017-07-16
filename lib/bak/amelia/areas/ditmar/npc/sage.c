#include <lib.h>
#include "ditmar.h"
inherit LIB_SAGE;

static void create() {
   sage::create();
   SetTown("Ditmar");
   SetKeyName("Samdar");
   SetShort("Samdar the Wise");
   SetId( ({ "wise","sage","samdar" }) );
   SetAdjectives( ({ "wise" }) );
   SetLong("Samdar is an old, short, fat, hunched-over mar.  In his youth, he would "
           "try to gain knowledge from all passing travellers, but has given up on "
           "that and know just gives his knowledge to anyone interested.  He "
           "knows how to teach languages like marin and drakem and eltherian, though.");
   SetRace("mar");
   SetClass("valkyr");
   SetGender("male");
   SetLevel(6);
   SetLocalCurrency("kuique");
   SetCharge(900000);
   SetLanguage("Marin",100,1);
   SetLanguage("Drakem",100);
   SetLanguage("Eltherian",100);
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
}