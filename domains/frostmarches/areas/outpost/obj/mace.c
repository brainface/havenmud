#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mace");
  SetShort("a heavy mace");
  SetAdjectives( ({ "heavy" }) );
  SetId( ({ "mace" }) );
  SetLong("This heavy mace has four blunted blades on a large iron head. "
          "The long handle allows the wielder to have control over this "
          "heavy weapon.");
  SetClass(25);  
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetDamagePoints(2000);
  SetValue(500);
  SetMass(200);  
  SetRepairDifficulty(30);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  }