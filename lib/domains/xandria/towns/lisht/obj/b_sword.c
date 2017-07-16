//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bronze sword");
  SetShort("a bronze sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "bronze" }) );
  SetClass(12);
  SetMass(70);
  SetValue(30);
  SetWeaponType("slash");
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetLong(
    "This is a finely crafted sword of bronze. The hilt "
    "is shaped like a rearing cobra about to strike, and "
    "the edge is marred with many small, buffed-out nicks, "
    "as if it has severed many souls from their bodies.");
  SetMaterial( ({ "metal" }) );
  SetDamagePoints(1700);
}
