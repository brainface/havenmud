#include <lib.h>
#include <std.h>
inherit LIB_STORAGEBOX;

static void create(string town, string owner) {
  ::create();
  if (!town || !owner) return;
  SetKeyName("chest");
  SetId( ({ "chest", "box", town + "_" + owner + "_storage" }) );
  SetShort("a large wooden chest");
  SetAdjectives( ({ "large", "wooden" }) );
  SetLocked(1);
  SetClosed(1);
  SetKey(town + "_" + owner + "_key");
  SetBoxID(town + "_" + owner + "_storage");
  SetLockStrength(1250); // possible ~ lvl 50, trivial ~lvl 100
  SetMaxCarry(1000000);
  SetLong("This large wooden box looks like it could hold much loot. "
          "It looks durable.");
  SetPreventGet("The box is firmly nailed to the floor.");
}
