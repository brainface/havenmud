/*
* mahkefel 3/22
* barbed devil natural weapon
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("chitinous spike");
  SetShort("chitinous spike");
  SetLong(
    "This is a spur severed from some vile creature's "
    "carapace. Tiny barbs cover the surface as it narrows "
    "to a single jagged point. The base of the spur where "
    "the break occured is relatively smooth and provides "
    "some area for gripping."
  );

  SetId( ({"spur","barb","spike"}) );
  SetAdjectives(({"chitinous"}));
  SetClass(20);
  SetDamagePoints(3000);
  SetDamageType(PIERCE);
  SetHands(1);
  SetMass(20);
  SetMaterial("natural");
  SetProperty("history",
    "This is a spike severed from the hand of a "
    "barbed devil, a resident of the lower planes. "
  );
  SetRepairDifficulty(50);
  SetValue(600);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
}
