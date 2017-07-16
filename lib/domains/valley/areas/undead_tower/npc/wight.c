///   Created by Severen   ///
///      Late December     ///
///        wight.c         ///

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create() {
    npc::create();

    SetKeyName("wight");
    SetId("figure");
    SetAdjectives("large","shadowy");
    SetShort("the shadowy figure of a wight");
    SetLong("Barely noticeable in the darkness is this wight. A "
      "figment of shadow from the darker spectrum of the undeath. It is "
      "rather large and moves sharply like the flicker of candlelight. "
      "A faint red glow comes from where its eyes would be.");
    
    
    SetRace("wraith","wight");
    SetClass("rogue");
    SetUndead(1);
    SetUndeadType("wight");
    SetLevel(10);
    SetMorality(-150);
    SetGender("neuter");
    SetEncounter(101);  
    SetInventory( ([ ]) );
    SetCurrency("rupies", random(20)+ 1);
    SetAction(10,({
			"!go out",
			"!go out",
			"!go out",
			"!climb staircase",
			"!climb down staircase",
      }));
    SetCombatAction(20, ({ 
			"!emote lashes out at you.",
			"!emote fades from view.",
			"!emote flickers with the movement of the lightsource.",
      }) );
}
