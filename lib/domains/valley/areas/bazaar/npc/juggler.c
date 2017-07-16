//
// Zimri the Juggler
// Created by Athalie
//

#include <lib.h>
inherit LIB_NPC;

static void create(){
  npc::create();
   SetKeyName("zimri");
   SetId( ({ "zimri", "juggler", "zimri the juggler" }) );
   SetShort("Zimri the juggler");
   SetLong("Zimri spends hours each day juggling and entertaining so that "
     "he can feed his family. He leaps and twirls and tosses the balls "
     "into the air with considerable skill. His fuzzy brownish hair is "
     "a little unkempt, and he looks quite tired.");
   SetGender("male");
   
   SetMorality(200);
   
   SetRace("muezzin");
   SetClass("merchant");
   SetLevel(4);
   SetCurrency("rupies", random(20));
   SetAction(5, ({
     "!emote does a cartwheel and catches the balls just before they hit the ground.",
   }) );
   SetCombatAction(5, ({
     "!emote whines pathetically.",
   }) );
}
