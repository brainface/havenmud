// cane for averath ferry captain
// mahk apr '10
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("cane");
  SetRepairDifficulty(22);
  SetMaterial( ({ "wood" }) );
  SetShort("an elegant cane");
  SetAdjectives( ({ "elegant", "long", "wooden" }) );
  SetId( ({ "cane" }) );
  SetLong(
    "This long cane is made of dark heart wood, sanded to a "
    "smooth finish. The handle is carved into the semblance of a "
    "dolphin head. It looks surprisingly sturdy for its weight."
  );
  SetClass(12);
  SetDamagePoints(1200);
  SetValue(180);
  SetMass(70);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
}

