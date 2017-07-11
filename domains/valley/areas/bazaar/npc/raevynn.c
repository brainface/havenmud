//
// Raevynn the fortune teller
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
inherit LIB_NPC;

static void create() {
  npc::create();
   SetKeyName("raevynn");
   SetId( ({ "raevynn", "woman" }) );
   SetAdjectives( ({ "mysterious", "gypsie" }) );
   SetShort("Raevynn, a mysterious gypsie woman");
   SetLong("Raevynn stands beside her glass ball protectively. She "
     "often runs her fingers over the surface and stares deep into the "
     "glass. Her black hair falls nearly to the floor, and her attire "
     "is in much better shape that any of the other bazaar attendants.");
   
   SetMorality(-20);
   SetGender("female");
   SetRace("elf");
   SetClass("enchanter");
   SetLevel(15);
   SetCurrency("rupies",random(100));
   SetAction(5, ({
     "!speak Those things which cannot be seen are now made apparent.",
     "!emote smiles seductively.",
   	 }) );
   SetSpellBook( ([
     "aura"     : 100,
     "missile"  : 100,
     "ice ball" : 100,
     ]) );
   SetCombatAction(5, ({
     "!cast aura",
     "!cast missile",
     "!cast ice ball",
     }) );
}
