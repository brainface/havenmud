// Proximo@Via Imperialis
// 06/16/2003

#include <lib.h>
#include <std.h>
inherit LIB_STORAGEBOX;

static void create() {
  ::create();
  SetKeyName("chest");
  SetId( ({ "chest", "jewel_chest" }) );
  SetAdjectives( ({ "storage" }) );
  SetShort("a storage chest");
  SetMaxCarry(800000);
  SetLocked(1);
  SetClosed(1);
  SetLockStrength(50000);
  SetLong(
     "This storage chest looks to have been made solid and sturdy. The thick wood boards are "
     "held together by a band of bent metal to keep the items within safe and secure. "
  );
  SetPreventGet("The storage chest is firmly attached to the floor. ");
  SetBoxID("jewel_chest");
}
