#include <lib.h>
#include <damage_types.h>
#include "../cata.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("zombie");
  SetId( ({ "zombie", "cata_npc" }) );
  SetShort("a rotting zombie");
  SetAdjectives( ({ "rotting" }) );
  SetLong("Decay has had it's way with the body of this zombie. Flesh"
          " hangs loosely from rotting muscle tissue that no longer"
          " is guarded by skin. His eyes have long since dried up"
          " leaving nothing but vacant cavities where they once were."
          " He is obviously a lost soul whose future is dependant"
          " upon the whim of his master.");
  SetGender("male");
  SetRace("human");
  SetUndead(1);
  SetUndeadType("zombie");
  SetNoCorpse(1);
  SetClass("horror");
  SetMorality(-500);
  SetLevel(95);
  SetAction(5, ({
  "!emote groans.",
  "!emote ambles about aimlessly.",
    }) );
  // mahkefel 2017: normalizing resistances to match animate undead
  SetResistance(GAS|HUNGER|POISON|DISEASE, "immune");
  SetResistance(BLUNT|SOUND, "low");
  SetResistance(SLASH|HEAT, "weakness");
}

