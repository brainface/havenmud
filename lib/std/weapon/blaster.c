#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("blaster");
  SetId( ({ "blaster" }) );
  SetAdjectives( ({ "low", "grade", "hand" }) );
  SetShort("a low-grade hand blaster");
  SetLong(
    "This blaster is of the type normally issued to new marines in the Imperial "
    "Marines. It is fairly standard in all ways."
  );
  SetClass(25);
  SetDamagePoints(1500);
  SetValue(150);
  SetWeaponType("beam");
  SetDamageType(HEAT|SHOCK);
  SetMass(50);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}

