#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_STORAGEBOX;

static void create() {
  ::create();
  SetKeyName("box");
  SetId( ({ "box", "tylus_storage", }) );
  SetAdjectives( ({ "storage", "large" }) );
  SetShort("a large storage box");
  SetMaxCarry(1000000);
  SetLocked(1);
  SetClosed(1);
  SetInventory( ([
    STD_FISH "oceanpole" : 2,
    ROME_OBJ "epicks" : 1,
    ROME_OBJ "spicks" : 1,
    ROME_OBJ "gpicks" : 1,
    ]) );
  SetLong("This is a large, durable storage box. It is owned "
          "by Tylus.");
  SetPreventGet("Tylus' box is nailed firmed to the floor.");
  SetBoxID("tylus_storage");
  SetLockStrength(500);
}
