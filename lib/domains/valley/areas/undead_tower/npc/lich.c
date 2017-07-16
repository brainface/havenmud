///   Created by Severen   ///
///      Late December     ///
///         lich.c         ///

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create() {
    npc::create();
		SetId("lich");
		SetAdjectives("horrible","bald","decayed","evil","unhappy","blackrobed");
    SetKeyName("Neffelin");
    SetShort("Neffelin, the Blackrobed Lich");
    SetLong("The horrible sight of this lich demands attention. "
      "Its eyes are a glossy black and lacks hair on its head. Its "
      "fingernails are extremely long and it moves with a grace like "
      "a cat. Most of its teeth are missing and decayed flesh covers "
      "its skeleton. It looks very evil and very unhappy.");
    SetUndead(1);
    SetRace("sprite");
    SetClass("necromancer");
    SetSkill("shock magic",1,2);
    SetLevel(15);
    SetMorality(-150);
    SetGender("female");
    SetEncounter(101);
    SetSpellBook(([
			"shock" 		 : 100,
			"bone shell" : 75,
			]));  
    SetInventory( ([
			TITEM + "/robe" : "wear robe",
			TITEM + "/sceptre" : "wield sceptre",
      ]) );
    SetCurrency("rupies", random(300));
    SetAction(10,({
			"!cast bone shell",
			"!go out",
			"!go out",
			"!go out",
			"!climb down stairs",
			"!climb staircase",
      }));
    SetCombatAction(70, ({ 
			"!cast bone shell",
			"!cast shock",
      }) );
}
