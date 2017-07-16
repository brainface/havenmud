#include <lib.h>
#include "../parva.h"
inherit LIB_TELLER;

static void create() {
   teller::create();
   SetTown("Parva");
   SetKeyName("Magna");
   SetShort("Magna the Treasurer of Parva");
   SetMorality(-400);
   SetId( ({ "magna", "treasurer", "parva_wander", "banker", "teller" }) );
   SetAdjectives( ({ }) );
   SetGender("female");
   SetRace("human");
   SetLong(
    "Magna is a very ugly lady with a shrewd head for numbers."
    " She has pock marks and freckles littering her face and"
    " destroying what once might of been a plain, if not"
    " moderately attractive visage. Her arms and legs are"
    " flabby and weak looking, but undoubtedly after having"
    " spent years carrying large sums of money she has some"
    " way of defending herself."
    );
   SetClass("merchant");
   SetSkill("melee combat", 1, 2);
   SetLevel(20);
   SetBankName("Parva Bank");
   SetLocalCurrency("oros");
   SetLocalFee(20);
   SetNonLocalFee(340);
   SetExchangeFee(0.08);
   SetInventory( ([
     ]) );
   SetAction(15, ({ 
    "!say The Parva Treasury is a safe place to keep your funds. Simply "
    "<request account from magna> and I will set you up.",
    }) );
   SetCombatAction(10, ({ 
     "!say I will not surrender the coins that I guard!",
     }) );
}
