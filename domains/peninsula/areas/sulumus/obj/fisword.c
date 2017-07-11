// Proximo@Pax Imperialis

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "fine", "iron", "short" }) );
  SetShort("a fine iron short sword");
  SetLong(
      "The techniques used to create this sword where from a carefully and "
      "skillfully forged piece of metal. The blade of the weapon has a new shine, "
      "brightly it gleams when shone in the light. The handle's grip was made from a "
      "soft but coarse leather, providing a good surface for grip. "
  		);
  SetClass(21);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetMass(200);
  SetValue(195);
  SetDamagePoints(1850);
}
