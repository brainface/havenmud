// mahkefel 201111
// faaancy rapier
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("elegant rapier");
  SetId( ({"rapier"}) );
  SetAdjectives( ({ "elegant" }) );
  SetShort("an elegant rapier");
  SetLong(
    "This long, narrow blade definitely couldn't stand up to "
    "too much punishment. However, it seems designed by skilled "
    "hands to pierce past chinks in armour and deliver mortal enough "
    "wounds to unprotected flesh. The crosshilt is made of thick steel, "
    "capable of deflecting a malicious blade and protecting the "
    "wielder's hand."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(5000);
  SetWeaponType("pierce");
  SetDamageType(PIERCE); // shrug.
  SetMass(50);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

