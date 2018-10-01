#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("lance");
  SetShort("a blood lance");
  SetLong(
    "A long lance with a wooden shaft and a "
    "barbed point made of a hard red metal."
  );
  SetId( ({ "lance", "blood lance" }) );
  SetAdjectives( ({ "long"}) );
  SetHands(2);  // Added by Duuk.  I mailed you about this.
  SetClass(13);
  SetDamagePoints(1750);
  SetValue(300);
  SetMass(75);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMaterial( ({ "metal", "wood" }) );
  SetRepairSkills( ([
    "weapon smithing" : 3,
    "wood working" : 1 
  ]) );
  SetRepairDifficulty(10);
}
