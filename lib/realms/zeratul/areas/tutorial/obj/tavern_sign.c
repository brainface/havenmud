//Zeratul@Haven - Adam Haye
//09/12/2013

#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a prominent sign");
  SetLong(
      "A sign hanging from the ceiling stating the purpose of these three rooms. "
      "Type <read sign> to learn more. "
  );
  SetRead(
      "default",
      "\n%^MAGENTA%^BOLD%^Training facilities%^RESET%^"
      "\nNorth: Melee (non-magic/combat) trainers."
      "\nEast:  Casting (magic/combat) trainers. "
      "\nSouth: Non-combat (trade/crafting) trainers. "
  );
  SetId( ({ "sign" }) );
  SetMaterials( ({ "wood" }) );
  SetAdjectives( ({ "prominent", "hanging" }) );
  SetKeyName("sign");
  SetPreventGet("The sign is firmly attached to the ceiling.");
}
