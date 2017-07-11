/* An intentionally poor weapon
 * might be useful if someone needs to actually
 * not deal damage, I don't know
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a practice foil");
  SetId( ({ "foil" }) );
  SetAdjectives( ({ "practice","wooden" }) );
  SetKeyName("foil");
  SetLong(
    "This wooden foil sports a rounded tip, and looks incapable "
    "of harming anyone. It would be an ideal weapon for practice "
    "spouts, which is likely its intended purpose. A metal core "
    "gives the weapon some durability."
  );
  SetClass(2);
  SetDamagePoints(1000); // it's somewhat tough
  SetValue(20); // it's cheap
  SetWeaponType("pierce");
  SetDamageType(BLUNT); // rounded tip
  SetMass(100); // somewhat weighty
  SetMaterial( ({ "wood" }) ); //wooden
  SetVendorType(VT_WEAPON);
}

