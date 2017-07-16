#include <lib.h>
#include "../forest.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("goblin adeptus");
  SetShort("a goblin adeptus");
  SetLong("This goblin as small compared to even a normal goblin.  He "
    "wears the robes of a mage and looks slightly more intelligent than "
    "his friends in the area.");
  SetId( ({ "adeptus", "goblin adeptus", "dark robed mage", "goblin" }) );
  SetRace("goblin");
  SetClass("evoker");
  SetLevel(random(3)+10);
  SetMorality(-150);
  SetGender("female");
  SetSpellBook( ([
     "fireball" : 70,
     "missile" : 90,
    ]) );
  SetInventory( ([
                   F_OBJ + "pole" : "wield pole",
              ]) );
  SetCurrency("imperials", random(100));
  SetCombatAction(20, ({
                        "!cast fireball",
                        "!cast missile",
                  }) );
 }
