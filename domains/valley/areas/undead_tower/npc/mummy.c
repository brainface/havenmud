///   Created by Severen   ///
///      Late December     ///
///        mummy.c         ///

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create() {
    npc::create();

    SetKeyName("mummy");
    SetId("mummy");
    SetAdjectives("wrapped","white","small");
    SetShort("a mummy wrapped in white cloth");
    SetLong("White cloth wrapping is draped around this mummy. "
      "It moves around in a steady marching movement. It's head is "
      "completely covered and no features can be seen about its racial "
      "characteristics. It is rather small compared to a human. "
      );
 
    SetRace("sprite");
    SetClass("rogue");
    SetLevel(5);
    SetUndead(1);
    SetUndeadType("mummy");
    SetSkill("necromancy", 40 , 1);
    SetSkill("conjuring",40,1);
    SetSpellBook(([
			"acid blast" : 100,
      ]));
    SetLevel(random(6)+10);
    SetMorality(-150);
    SetGender("neuter");
    SetEncounter(101);  
    SetInventory( ([ 
    	]) );
    SetCurrency("rupies", random(20)+1);
    SetCombatAction(80, ({ 
			"!emote 's wrapings come undone along its waist.",
			"!cast acid blast",
			"!emote moans loudly.",
			"!emote 's wrapings come undone along its feet.",
      }) );
}
