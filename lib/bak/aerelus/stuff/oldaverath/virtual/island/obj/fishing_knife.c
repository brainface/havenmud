#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetShort("a fishing knife");
  SetId( ({ "knife", "fishing knife" }) );
  SetAdjectives( ({ "fishing" }) );
  SetLong("A small knife used to gut and clean fish. It has "
          "a notch in the tip.");
  SetClass(12);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetDamagePoints(500);
  SetValue(10);
  SetVendorType(VT_WEAPON);
 }
