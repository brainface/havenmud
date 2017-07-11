#include <lib.h>
#include "../camp.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("bandit mage");
  SetShort("a dark robed bandit mage");
  SetId( ({ "mage", "bandit mage", "dark robed mage", "bandit" }) );
  SetRace("human");
  SetClass("evoker");
  SetLevel(random(8)+8);
  SetMorality(-150);
  SetAction(1, ({
       "!speak You can have any of my old staves.",
      }) );
  SetGender("male");
  SetSpellBook( ([
     "ice ball" : 100,
     "missile" : 100,
     "buffer" : 100,
     "aura" : 100,
    ]) );
  SetInventory( ([
    "std/clothing/body/black_robe" : "wear robe",
     CAMP_OBJ + "staff" : "wield staff",
     ]) );
  SetCurrency("imperials", random(100)+10);
  SetCombatAction(35, ({ 
      "!cast fireball",
       "!cast missile",
        "!cast bolt",
        "!cast buffer",
        "!cast aura",
    }) );
  SetLong("This dark robed mage has a sinister sneer on his face that "
          "chills the souls of the weak willed.");
 }
