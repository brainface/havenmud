//Illura@Haven
//Sept 2009
//whitefrost
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("whitefrost");
  SetId( ({ "whitefrost" }) );
  SetAdjectives( ({ "ancient" }) );
  SetShort("whitefrost, the ancient");
  SetLong(
    "Whitefrost looms several stories high, very sturdy and "
    "almost tree-like. It is hard to tell whether he is rimmed "
    "with frost crystals or thick white hide, but his face seems "
    "almost humanoid, with a long frost beard, almost twiggy "
    "at the ends. His penetrating eyes are deep, slow, and "
    "full of deadly patience."
  );
  SetClass("necromancer");
  SetLevel(110);
  SetGender("male");
  SetRace("gargoyle");
  SetAction(5, ({
    "!emote waggles his beard at you, eyes twinkling with hidden mirth.",
    "!emote almost looks surprised to see you. Or anyone, for that matter.",
    "!emote gestures toward the stars expansively.",
                })  );
  SetSpellBook( ([
                "vampiric touch" : 100,
                "veil from beyond" : 100,
                "wither" : 100,
               ]) );
  SetCombatAction(50, ({
    "!cast vampiric touch",
    "!cast veil from beyond",
    "!cast wither",
    }) );
  SetInventory( ([
    TAIGA_OBJ "staff" : "wield staff",
      ]) );
  SetDie("A distant star crashes into the ocean as the ancient falls.");
}
