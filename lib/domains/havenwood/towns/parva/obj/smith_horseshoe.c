//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a horseshoe");
  SetId( ({ "horseshoe" }) );
  SetKeyName("horseshoe");
  SetLong(
     "This is a heavy iron horseshoe, used to keep "
     "the hooves of horses from wear and tear. The "
     "curving bit of iron could probably be used "
     "in combat, in a pinch. "
  	 );
  SetClass(15);
  SetDamagePoints(1200);
  SetValue(50);
  SetWeaponType("melee");
  SetDamageType(BLUNT);
  SetMass(90);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetVendorType(VT_WEAPON);
}
