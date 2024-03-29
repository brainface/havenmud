#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("a huge longsword");
  SetLong("This oversized longsword is beyond comprehension. "
          "Its thick blade is clearly made to cleave opponents in half "
          "before the battle begins.");
  SetId( ({ "sword", "longsword" }) );
  SetAdjectives( ({ "huge" }) );
  SetClass(50);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetDamagePoints(9600);
  SetValue(36000);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("huge longsword");
	SetMass(375);
	SetVendorType(VT_WEAPON);
}


