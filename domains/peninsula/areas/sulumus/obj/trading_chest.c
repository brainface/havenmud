// Proximo@Via Imperialis
// 06/01/2003

#include <lib.h>
#include <std.h>
inherit LIB_STORAGEBOX;

static void create() {
  ::create();
  SetKeyName("chest");
  SetId( ({ "chest", "trading_chest" }) );
  SetAdjectives( ({ "storage", "large" }) );
  SetShort("a large storage chest");
  SetMaxCarry(1000000);
  SetLocked(1);
  SetClosed(1);
  SetLockStrength(50000);
  SetLong(
     "This large storage chest looks to have been made solid and sturdy. The "
     "thick wood boards held together by a band of bent metal keep the items "
     "within safe and secure. "
  	 );
  SetPreventGet("The storage chest is firmly attached to the floor. ");
  SetBoxID("trading_chest");
}
