//
// A human explorer
// Created by Zaxan@Haven
//

#include <lib.h>
#include "path.h"

inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("explorer");
   SetId( ({ "explorer" }) );
   SetAdjectives( ({ "human" }) );
   SetShort("a human explorer");
   SetLong("This explorer in the mountains looks as if he's taken "
           "a wrong turn. His body is shriveled to almost nothing, "
           "and one of his arms looks broken. His skin looks about "
           "ready to fall off of his weak skeleton.");
   SetAction(5, ({ 
      "!shiver",
      "!speak Where am I?",
      "!speak We had almost made it!",
      "!speak I beg of you! Help me!",
   }) );
   SetCombatAction(5, ({ 
      "!speak Why won't you help me?",
   }) );
   SetDie("Explorer says %^BOLD%^CYAN%^\"Yes...put me out of my misery...\"%^RESET%^");
   SetGender("male");
   
   SetRace("human");
   SetClass("fighter");
   SetLevel(2);
   SetCurrency("senones",random(10)+1);
   RemoveLanguage("Enlan");
   SetLanguage("Eetria", 100, 1);
}
