//Illura@Haven
//Sept 2009
//grayhorn
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("grayhorn");
  SetId( ({ "grayhorn" }) );
  SetAdjectives( ({ "ancient" }) );
  SetShort("grayhorn, the ancient");
  SetLong(
    "Grayhorn is encased in ivory tusks and whipping "
    "stormwinds. His expansive horned limbs are hardened "
    "with the power of a thousand heroes. Forgotten magics "
    "well within him. Surmounted over twin ocean-blue "
    "swirling eyes is a huge pearly horn, razor sharp "
    "at the tip."
  );
  SetClass("mystic");
  SetLevel(110);
  SetGender("male");
  SetRace("gargoyle");
  SetAction(5, ({
    "!emote flexes and stretches, making shards of horn clatter to the ice.",
    "!emote lifts his horn skyward. The winds blow stronger.",
    "!emote blinks at you wordlessly.",
                })  );
  SetSpellBook( ([
                "ice storm" : 100,
                "full regeneration" : 100,
               ]) );
  SetCombatAction(50, ({
    "!cast ice storm",
    "!cast full regeneration",
    }) );
  SetInventory( ([
    TAIGA_OBJ "staff" : "wield staff",
      ]) );
  SetDie("A distant star crashes into the ocean as the ancient falls.");
}
