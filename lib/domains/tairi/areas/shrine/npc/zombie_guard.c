
#include <lib.h>
#include "../shrine.h"


inherit LIB_NPC;
int DoGuard();
static void create() {
  npc::create();
  SetKeyName("zombie");
  SetId( ({ "zombie", "guard", "menace" }) );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Tai");
  SetClass("fighter");
  SetShort("a menacing zombie guard");
  SetLong("Rotten and decayed beyond recognition, this"
          " zombie stands guard with a blank expression."
          " His skin flakes off and drifts away in the wind"
          " and the odor of death creates a miasma around him."
          " He has been summoned by the necromancer Taketori.");
  SetMorality(-1000);
  SetLevel(20);
  SetCombatAction(50, ({
    "!growl",
    "!emote swings his arms around causing clumps of skin to fall off.",
    }) );
  SetAction(50, ({
    "!guard taketori",
    }) );
  SetUndead(1);
  SetUndeadType("zombie");
  SetFirstCommands( ({ 
    "guard taketori", 
    }) );
  SetFriends( ({ "zombie", "taketori" }) );
 }

