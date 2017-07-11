//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("crossbow");
  SetMaterial("natural");
  SetRepairDifficulty(10);
  SetShort("a heavy crossbow");
  SetId( ({ "crossbow", "bow" }) );
  SetAdjectives( ({ "heavy", "cross" }) );
  SetLong("This is a heavy, dangerous crossbow constructed "
          "from hardwood. It could probably put a bolt through "
          "plate mail from a mile away.");
    SetValue(1200);
  SetClass(12);
  SetMass(75);
  SetDamageType(PIERCE);
  SetWeaponType("projectile");
  SetDamagePoints(1000);
  SetVendorType(VT_WEAPON);
  }
