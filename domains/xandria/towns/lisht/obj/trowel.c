// mahkefel 2013
// lisht digger
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
  item::create();
  SetKeyName("trowel");
  SetHands(1);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetDamagePoints(500);
  SetValue(50);
  SetClass(10);
  SetShort("a bronze trowel");
  SetAdjectives(({"bronze"}));
  SetMaterial( ({ "wood", "metal" }) );
  SetRepairDifficulty(10);
  SetMass(60);
  SetId( ({ "trowel" }) );
  SetLong("This simple trowel is made of cheap bronze and wastewood. "
    "It looks perfect for bricklaying or weed pruning. Or at least "
    "vaguely better than your bare hands.");
  SetVendorType(VT_WEAPON);
  }

