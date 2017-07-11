#include <lib.h>
inherit LIB_BARKEEP;
#include "../monastery.h"

static void create() {
   barkeep::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("Dara");
   SetShort("Dara, the barkeep");
   SetId( ({ "barkeep","barkeeper","dara" }) );
   SetAdjectives( ({ }) );
   SetLong("Dara smiles happily, enjoying her position as the barkeeper "
           "for the Eclats around here.  She is short and plump, doing "
           "little but serving drinks around here.");
   SetRace("muezzin");
   SetClass("fighter");
   SetSkill("bargaining",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(25);
   SetGender("female");
   SetLocalCurrency("cuicui");
   SetMenuItems( ([
          "meza" : M_OBJ + "meza",
          "stew" : M_OBJ + "stew",
          "brownie" : M_OBJ + "brownie",
          "bread" : M_OBJ + "bread",
          "beer" : M_OBJ + "beer",
               ]) );
   SetCurrency("cuicui", random(10)+1);
   SetMorality(500);
}