// Amelia May 01
#include <lib.h>
#include <domains.h>
inherit LIB_TELLER;

void CallGuards();

static void create() {
   ::create();
   SetTown("Averath");
   SetKeyName("Orris");
   SetShort("Orris the Banker");
   SetId( ({ "teller","banker","orris" }) );
   SetAdjectives( ({ "orris","the","teller","banker" }) );
   SetLong("Orris has nobby elbows that poke through his skin, "
           "and long, skinny fingers with soft, manicured nails "
           "that show no signs of an honest day's labor.  Orris "
           "constantly squints at the surrounding area, unable "
           "to see far into the distance.  He runs the First "
           "Averath Bank.");
   SetGender("male");
   SetRace("human");
   SetSkill("melee attack",5);
   SetSkill("melee defense",5);
   SetCurrency("ducats",50);
   SetCurrencies( ({ "ducats" }) );
   SetLocalFee(3);
   SetNonLocalFee(10);
  SetExchangeFee(2.0);
   SetMorality(25);
   SetBankName("First Averath Bank");
   SetAction(2, ({ "!say I run the First Averath Bank.","!say I can "
                   "store your moneys safely while you adventure.",
                   "!say You don't have to worry about thieves "
                   "when your ducats are with me!", }) );
   AddTalkResponse("ducats","Store your ducats here while you're "
                   "adventuring.  Just 3 ducats to open an account "
                   "for locals.");
   AddTalkResponse("bank","I run this bank, the First Averath Bank.  "
                   "Store your ducats here for safekeeping.");
   SetLocalCurrency("ducats");
   SetCombatAction(15, ({ (: CallGuards :),"!emote shrieks.",
                         "!emote whimpers.","!say Help!  Oh help!",
//                         "!shout Help!  I'm being attacked!"
                          }) );
}

void CallGuards() {
   object der;
   if(der = present("guard",environment(this_object()))) {
      der->eventForce("speak I will protect Orris!");
      der->eventForce("attack" + 
           GetEnemyNames()[random(sizeof(GetEnemyNames()))]);
      return;
   }
   der = new(AVERATH_NPC + "bankguard");
   der->eventMove(environment(this_object()));
   der->eventForce("say Die, scum!");
   der->eventForce("attack " + 
           GetEnemyNames()[random(sizeof(GetEnemyNames()))]);
   return;
}
