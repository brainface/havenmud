//Illura@Haven
//Sept 2009
//chillfang
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("chillfang");
  SetId( ({ "chillfang" }) );
  SetAdjectives( ({ "ancient" }) );
  SetShort("chillfang, the ancient");
  SetLong(
    "Chillfang embodies the deadly power of the tundra. "
    "His mighty teeth are encased in a layer of blueish ice "
    "crystal, and his hide is studded with rocks and chunks "
    "of green-rimed icebergs. His ancient cruelty knows no "
    "bounds."
  );
  SetClass("necromancer");
  SetLevel(110);
  SetGender("male");
  SetRace("gargoyle");
  SetAction(5, ({
    "!emote glares at you with his eyes, one verdant green, the other as blue as
 the deepest depths of the sea.",
    "!emote opens his maw to show row upon row of sharp teeth.",
    "!emote holds his claws up to the sky and bellows.",
                })  );
SetSpellBook( ([
                "vampiric touch" : 100,
                "soultap" : 100,
               ]) ); 
 SetCombatAction(50, ({
    "!cast vampiric touch",
    "!cast soultap",
    }) );
  SetInventory( ([
    TAIGA_OBJ "staff" : "wield staff",
      ]) );
  SetDie("A distant star crashes into the ocean as the ancient falls.");
}
