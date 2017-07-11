#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("an iron mace");
  SetLong(
    "The heavy iron head of this mace is "
    "attached to a stout oaken handle. "
  );
  SetId( ({"mace", "iron mace","iron"}) );
  SetAdjectives( ({ "iron" }) );
  SetClass(12);
  SetDamagePoints(1200);
  SetValue(300);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("mace");
  SetMass(200);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
