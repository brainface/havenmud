// Proxy

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "crude", "walking" }) );
  SetShort("a crude walking staff");
  SetMaterials( ({ "wood" }) );
  SetLong(
     "This staff looks to have been designed for the specific purpose of helping keep a person upon "
     "their feet. The staff is full of knobs, bends, and gouges, making this staff not so much a "
     "staff but more like simply a large branch with a grip cut into it. This staff might not "
     "look fancy nor be intended to be presented in battle, but it serves it's purpose as a fine walking "
     "staff. "
  );
  SetClass(1);
  SetHands(2);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetMass(215);
  SetValue(10);
  SetDamagePoints(980);
}
