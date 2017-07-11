// mahkefel 20101117
// pirate knife
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("jeweled dagger");
  SetId( ({"dagger"}) );
  SetAdjectives( ({ "jeweled" }) );
  SetShort("a jeweled dagger");
  SetLong(
    "The ostentateous hilt of this dagger is set with "
    "glowing rubies and sapphires, all wrapped in golden "
    "filagree. Though perhaps difficult to realize beyond "
    "all the glare of sparkling gemstones, the long and "
    "slender blade is honed to razor sharpness and terminates "
    "in a needle sharp point."
  );
  SetClass(27);
  SetDamagePoints(2000);
  SetValue(5000);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetMass(250);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

