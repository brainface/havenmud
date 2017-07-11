// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include "../sewers.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("muscular bandit");
  SetShort("a muscular bandit");
  SetId( ({ "bandit" }) );
  SetAdjectives( ({ "muscular" }) );
  SetLong(
    "This extremely strong man blends into the shadows with ease. His face is "
    "completely hidden. He glances around, checking for movement in the "
    "shadows, though seems confident of handling any problems that arise from "
    "them."
        );  
  SetRace("human");
  SetClass("rogue");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetLevel(random(10) + 10);  
  AddCurrency("ducats", random(150)+1);
  SetCombatAction(1, ({
    "!say You had better be carrying some ducats.",
    "!emote moves almost gracefully, seeking an opportunity to strike.",
  }) );
  SetAction(3, ({
    "!emote methodically checks the shadows for movement.",
    "!glance",
  }) );
  SetInventory( ([ 
     SEWERS_OBJ "jorin_knife" : "wield knife",
     SEWERS_OBJ "rogue_robe" : "wear robe",      
  ]) );
  SetEncounter(0);
  SetMorality(-200);
}
