///   Created by Severen   ///
///      Late December     ///
///        sprite.c        ///
// mahkefel july 2010: copy of severen's sprites with climbing removed.
// trying to keep absurd numbers of sprites from accumulating in hall.

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create() {
    npc::create();

    SetKeyName("sprite");
    SetShort("a sprite in tattered clothing");
    SetLong("Swaying back and forth is a sprite zombie. "
      "He is bald and his eyes are a milky white color. His "
      "clothing is tattered and he is barefoot.");
    SetId("zombie");
    SetAdjectives("bald","barefoot","undead","zombie");
    SetRace("sprite");
    SetClass("rogue");
    SetSkill("pole combat",1,2);
    SetLevel(2);
    SetUndead(1);
    SetGender("male");
    SetEncounter(101);  
    if(!(random(3))) {
			SetInventory( ([
	    	TITEM + "/staff" : "wield staff",
	    	TITEM + "/pants" : "wear pants",
	   		TITEM + "/shirt" : "wear shirt",
	  		]) );
    	}
    else {
			SetInventory( ([
	    	TITEM + "/knife" : "wield knife",
	    	TITEM + "/pants" : "wear pants",
	    	TITEM + "/shirt" : "wear shirt",
	  		]) );
    	}
    SetCurrency("rupies", random(70)+1);
    SetCombatAction(20, ({ 
			"!emote hisses at you.",
			"!emote grins maliciously.",
			"!emote looks very angry.",
      }) );
}
