#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetId( ({ "sword", "longsword" }) );
  SetAdjectives( ({ "mithril", "long" }) );
  SetShort("a mithril longsword");
  SetLong(
    "The finely crafted mithril blade of this "
    "sword gleams in the light."
  );
  SetClass(24);
  SetDamagePoints(5800);
  SetValue(3600);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(175);
  SetMaterial( ({ "mithril" }) );
  SetRepairDifficulty(60);
  SetVendorType(VT_WEAPON);
}


