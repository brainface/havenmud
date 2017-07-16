#include <lib.h>
inherit LIB_HEALER;
#include "../monastery.h"

static void create() {
   healer::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Kaleid");
   SetShort("Kaleid, a joyous healer");
   SetId( ({ "kaleid","healer" }) );
   SetAdjectives( ({ "joyous" }) );
   SetLong("Kaleid has soft fur and smiles very happily.  He looks "
           "as if he has been training in the arts of Eclat "
           "for a very long time.");
   SetReligion("Eclat","Eclatish");
   SetClass("cleric");
   SetRace("muezzin");
   SetLevel(45);
   SetGender("male");
   SetLocalCurrency("cuicui");
   
  SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
   SetMorality(800);
   SetFriends( ({ }) );
   SetSpellBook( ([
                    "sanctify" : 100,
               ]) );
   SetCombatAction(50,({ "!cast sanctify" }) );
   SetInventory( ([
                    M_OBJ + "robe" : "wear robe",
               ]) );
   SetCurrency("cuicui",3000);
}