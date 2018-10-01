#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("sword");
  SetShort("a red bladed longsword");
  SetLong(
    "A finely crafted longsword with a blade "
    "made of a reddish metal."
  );
  SetId( ({"red bladed sword", "red sword", "red longsword",
          "longsword"}) );
  SetAdjectives( ({ "long"}) );
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(500);
  SetMass(60);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
}

