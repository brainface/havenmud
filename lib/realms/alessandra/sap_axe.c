
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("broken woodaxe");
  SetId( ({"axe","woodaxe"}) );
  SetAdjectives( ({ "broken", "wood" }) );
  SetShort("a broken woodaxe");
  SetLong(
    "A split handle of rotten wood connects "
    "to a rusty, jagged axeblade that has "
    "apparently seen much ill use. Living "
    "vines spiral up the handle and encircle "
    "the blade, holding the failing tool together."
  );
  SetClass(22);
  SetDamagePoints(2000);
  SetValue(50);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetMass(350);
  SetMaterial( ({ "metal","wood" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

