//
// Graxian the Stiltwalker
// Created by Athalie
//

#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
   SetKeyName("graxian");
   SetId( ({ "graxian", "stiltwalker", "graxian the stiltwalker" }) );
   SetShort("Graxian the stiltwalker");
   SetLong("Graxian carefully picks his way around, trying not to step on "
     "anyone's toes. He spends most of his time here at the bazaar so that "
     "he will be able to pay his bills. His long billowy pants are tattered "
     "with wear, and his long red hair hasn't been washed in quite a while.");
   
   SetGender("male");
   SetMorality(50);
   SetRace("sprite");
   SetClass("merchant");
   SetLevel(6);
   SetCurrency("rupies", random(50));
   SetAction(2, ({
     "!emote spreads his arms for balance.",
     "!emote lumbers around the room, looking for donations.",
   }) );
   SetCombatAction(5, ({
     "!emote swings one of his stilts at you angrily.",
   }) );
}
