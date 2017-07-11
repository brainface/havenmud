// mahkefel 2011
// lisht knife
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mace");
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "bronze" }) );
  SetShort("a bronze mace");
  SetLong(
    "This bronze mace has been shaped to resemble the head of "
    "a falcon. The beak looks sharp enough to penetrate armour with "
    "a good enough swing, or someone could crush a skull with the back "
    "end. The wooden handle provides a firm enough grip."
  );
  SetMass(60);
  SetValue(100);
  SetClass(17);
  SetVendorType(VT_WEAPON);
  SetWeaponType("blunt");
  SetDamageType(BLUNT|PIERCE);
  SetDamagePoints(1000);
  SetMaterial( ({ "metal" }) );
}

