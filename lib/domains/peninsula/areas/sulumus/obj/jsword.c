// Proximo@Via Imperialis
// 06/01/2003

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("jewel-encrusted sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "a", "jewel", "encrusted", "bronze" }) );
  SetShort("a jewel-encrusted bronze sword");
  SetLong(
     "Upon first glance of this weapon, it is obvious that, by the fancy "
     "jewels that have been engraved in the sword, that this weapon was designed "
     "as a sword to display, not to fight with. While it's fancy looks many give "
     "the appearance of that of a simple show sword, it is actually very sharp and "
     "quite effective at slicing through flesh and bone. "
  	 );
  SetClass(20);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetVendorType(VT_WEAPON);
  SetMass(190);
  SetValue(140);
  SetDamagePoints(1350);
}
