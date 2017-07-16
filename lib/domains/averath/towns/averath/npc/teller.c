#include <lib.h>
#include <domains.h>
inherit LIB_TELLER;

static void create() {
  ::create();   
  SetKeyName("Orris");   
  SetId( ({ "teller", "banker", "orris", "averath_person" }) );
  SetShort("Orris the Banker");   
  SetLong(
    "Orris has nobby elbows that poke through his skin, and long, skinny "
    "fingers with soft, manicured nails that show no signs of an honest "
    "day's labor. Orris constantly squints at the surrounding area, "
    "unable to see far into the distance. He runs the First Averath Bank."
  	);
  SetAdjectives( ({ "orris","the","teller","banker" }) );
        
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");  
  
  SetMorality(750);
  SetClass("rogue");
  SetLevel(15);
  AddCurrency("ducats", random(100)+10);    
   
  SetCurrencies( ({ "ducats" }) );
  SetLocalFee(1);
  SetNonLocalFee(5);
  SetExchangeFee(1.4);   
  SetTown("Averath");
  SetBankName("First Averath Bank");
  SetAction(2, ({ 
    "!say I run the First Averath Bank.","!say I can "
    "store your moneys safely while you adventure.",
    "!say You don't have to worry about thieves when your ducats are with "
      "me!", 
  	}) );
  AddTalkResponse(
    "ducats", "Store your ducats here while you're adventuring. Just 3 "
      "ducats to open an account for locals."
  );   
  AddTalkResponse(
    "bank", "I run this bank, the First Averath Bank. Store your ducats "
      "here for safekeeping."
  );
  SetLocalCurrency("ducats");
  SetCombatAction(15, ({ 
    "!emote shrieks.",
    "!emote whimpers.",
    "!say Help!  Oh help!",
  }) );
}
