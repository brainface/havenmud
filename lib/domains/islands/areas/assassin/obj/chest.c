#include <lib.h>
#include <std.h>
inherit LIB_STORAGEBOX;

static void create() {
  ::create();
  SetKeyName("chest");
  SetId( ({ "chest", "box", "assassin_storage" }) );
  SetShort("a large wooden chest");
  SetAdjectives( ({ "large", "wooden" }) );
  SetLocked(1);
  SetClosed(1);
  SetKey("assassin_key_001");
  SetBoxID("assassin_isle_chest");
  SetLockStrength(150);
  SetMaxCarry(1000000);
  SetLong("This large wooden box looks like it could hold much loot. "
          "It looks durable.");
  SetPreventGet("The box is firmly nailed to the floor.");
}
