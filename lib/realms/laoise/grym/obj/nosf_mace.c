#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("mace");
  SetShort("a red mace");
  SetLong(
    "A finely crafted mace with a head "
    "made of a reddish metal."
  );
  SetId( ({"red headed mace", "red mace"}) );
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(350);
  SetMass(75);
  SetVendorType(VT_WEAPON);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
}

