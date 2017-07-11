// mahkefel 2012
// elemental thing weapon
// fire-HEAT
// earth-ACID?
// air-SHOCK
// water-COLD

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("frost covered staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "frost","covered" }) );
  SetShort("a frost covered staff");
  SetLong(
    "This long oaken staff is permanently covered with a thin "
    "layer of hoarfrost. "
  );
  SetHands(2);
  SetClass(20);
  SetWeaponType("pole");
  SetDamageType(BLUNT|COLD);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(800);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(15);

  SetProperty("history","This weapon was stolen from an elemental "
    "guarding the magildan temple.");
  SetProperty("magic","You have a vague feeling this staff might be "
    "... look it's covered in ice figure it out.");
 }

