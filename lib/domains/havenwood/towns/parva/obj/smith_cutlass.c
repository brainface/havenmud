//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a weighty cutlass");
  SetId( ({ "cutlass", "sword" }) );
  SetAdjectives( ({ "weighty" }) );
  SetKeyName("cutlass");
  SetLong(
     "This heavy cutlass has a broad, curving blade "
     "of iron meant for slashing limbs off of the "
     "enemy from a shorter distance than the average "
     "sword. It is extremely useful, if heavy. "
  );
  SetClass(17);
  SetDamagePoints(1300);
  SetValue(50);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(90);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(20);
  SetVendorType(VT_WEAPON);
}