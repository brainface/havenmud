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
  SetKeyName("lightning split staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "lightning","split" }) );
  SetShort("a lightning split staff");
  SetLong(
    "This long oaken staff bears a channel of raw wood carved "
    "from end to end by the obvious violence of a lightning strike. "
    "The obvious deformity seems to have done nothing to weaken it. "
    "Occasionaly sparks spit and crackle along the split."
  );
  SetHands(2);
  SetClass(20);
  SetWeaponType("pole");
  SetDamageType(BLUNT|SHOCK);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(800);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(15);

  SetProperty("history","This weapon was stolen from an elemental "
    "guarding the magildan temple.");
  SetProperty("magic","You have a vague feeling this staff might be "
    "shockingly effective.");
 }

