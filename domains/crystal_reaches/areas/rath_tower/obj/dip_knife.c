#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("thin knife");
  SetShort("a small thin knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "small", "thin" }) );
  SetClass(11);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(500);
  SetLong("This small, thin knife is a stylized weapon used mostly "
          "for decoration of Rath Khan's diplomats.");
  SetValue(100);
  SetMass(35);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(10);
 }
