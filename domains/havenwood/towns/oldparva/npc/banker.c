#include <lib.h>
#include "parva.h"
inherit LIB_TELLER;

static void create() {
   teller::create();
   SetTown("Parva");
   SetKeyName("Magnum");
   SetShort("Magnum, banker of Parva");
   SetProperty("parvanoleave",1);
   SetMorality(90);
   SetId( ({ "magnum","teller","banker","of parva" }) );
   SetAdjectives( ({ "banker","magnum","the" }) );
   SetLong("Magnum is a scrawny, dark-skinned human.  "
           "He has long brown hair and dark brown eyes, "
           "and looks to have nimble fingers.  His face "
           "is gentle and kind, but bored.  He looks like "
           "he wants to be doing something, inventing "
           "something, or just employing his talents in a "
           "better way than here as a teller.");
   SetGender("male");
   SetRace("human");
   SetClass("evoker");
   SetSkill("pole combat",1,2);
   SetLevel(20);
   SetMorality(20);
   SetBankName("Parva Bank");
   SetLocalCurrency("oros");
   SetCurrencies( ({ "oros","imperials","bloodgems","cuicui",
                     "rounds" }) );
   SetLocalFee(20);
   SetNonLocalFee(340);
   SetExchangeFee(0.08);
   SetInventory( ([
                    P_OBJ + "/pants_banker" : "wear pants",
                    P_OBJ + "/shirt_banker" : "wear shirt",
                    // P_OBJ + "/gloves_banker" : "wear gloves",
                    P_OBJ + "/socks_banker" : "wear socks",
                    P_OBJ + "/boots_banker" : "wear boots",
                    P_OBJ + "/pole_banker" : "wield staff",
               ]) );
   SetSpellBook( ([
                    "acid blast" : 100,
                    "enhanced fireball" : 100,
                    "bolt" : 100,
                    "aura" : 100,
                    "chain lightning" : 100,
                    "channeling" : 100,
                    "missile" : 100,
                    "shock" : 100,
                    "terra" : 100,
               ]) );
   SetAction(2, ({ "!whistle","!smile","!emote looks bored.",
                   "!emote twiddles his fingers idly.","!cast "
                   "aura","!cast aura" }) );
   SetCombatAction(10, ({ "!yell Help!  Help me!","!yell Help me!  "
                    "I'm being attacked!","!yell Help!",
                    "!cast acid blast","!cast chain lightning",
                    "!cast bolt","!cast channeling","!cast "
                    "enhanced fireball","!cast missile",
                    "!cast shock","!cast terra" }) );
}
