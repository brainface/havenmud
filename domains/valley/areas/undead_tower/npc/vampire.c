///   Created by Severen   ///
///     Early December     ///
///       vampire.c        ///

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create() {
    npc::create();

    SetKeyName("Sbarra");
    SetShort("Sbarra, the seductive vampire");
    SetLong("The body of this female sprite vampire is flawless. "
      "She is naked and has pitch black hair which hangs to her "
      "waist. Her fangs look razor sharp and she looks very unhappy.");
    SetAdjectives("female","naked","flawless","undead","unhappy");
    SetId("vampire");
    SetRace("sprite");
    SetUndead(1);
    SetUndeadType("vampire");
    SetClass("rogue");
    SetLevel(8);
    SetMorality(-150);
    SetGender("female");
    SetEncounter(101);  
    SetInventory( ([
			TITEM + "/knife" : "wield knife",
      ]) );
    SetCurrency("rupies", random(100)+ 6);
    SetCombatAction(20, ({ 
			"!emote hisses at you.",
                        "!say Now, you will die!",
			"!cackle",
      }) );
}
