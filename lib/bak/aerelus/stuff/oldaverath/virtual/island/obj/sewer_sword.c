#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("warped sword");
  SetShort("a warped and abused sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "warped", "abused" }) );
  SetClass(7);
  SetMass(50);
  SetValue(2);
  SetLong("This pathetic sword has been down in the sewers, rotting and bending "
          "since the time it was lost. It has very little worth to anyone who is "
          "not desperate for a weapon.");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetWeaponType("slash");
}
