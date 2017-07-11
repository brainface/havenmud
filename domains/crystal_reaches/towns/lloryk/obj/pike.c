#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("pike");
  SetHands(2);  // Balanced this a little -- Duuk
  SetId( ({ "pike" }) );
  SetAdjectives( ({ "sharp", "long" }) );
  SetShort("a long sharp pike");
  SetLong("The sharp blade of the pike tops a four foot staff.");
  SetMass(150); 
  SetMaterials( ({ "metal", "wood" }) );
  SetValue(150);
  SetRepairDifficulty(15);
  SetDamagePoints(800);
  SetWeaponType("pole");
  SetDamageType(PIERCE);
  SetClass(14);
  SetVendorType(VT_WEAPON);
}

