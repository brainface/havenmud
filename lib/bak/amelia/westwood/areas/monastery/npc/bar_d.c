#include <lib.h>
inherit LIB_BARKEEP;
#include "../monastery.h"

static void create() {
   barkeep::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Dara");
   SetShort("Dara, the barkeep");
   SetId( ({ "barkeep","barkeeper","dara" }) );
   SetAdjectives( ({ }) );
   SetLong("Dara smiles happily, enjoying her position as the barkeeper "
           "for the Eclats around here.  She is short and plump, doing "
           "little but serving drinks around here.");
   SetClass("valkyr");
   SetSkill("bargaining",1);
   SetLevel(10);
   SetGender("female");
   SetRace("muezzin");
   SetLocalCurrency("cuicui");
   SetMenuItems( ([
                    "meza" : M_OBJ + "meza",
                    "stew" : M_OBJ + "stew",
                    "brownie" : M_OBJ + "brownie",
                    "bread" : M_OBJ + "bread",
                    "beer" : M_OBJ + "beer",
               ]) );
   SetCurrency("cuicui",5200);
   SetMorality(500);
}