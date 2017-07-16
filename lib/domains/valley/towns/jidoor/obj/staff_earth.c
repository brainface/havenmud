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
  SetKeyName("vine  staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "vine","entwined" }) );
  SetShort("a vine entwined staff");
  SetLong(
    "This long oaken staff is tressed with several vines, green and "
    "healthy. Large, suspiciously oozing thorns make the weapon "
    "difficult to handle safely."
  );
  SetHands(2);
  SetClass(20);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetPoison(20);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(800);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(15);

  SetProperty("history","This weapon was stolen from an elemental "
    "guarding the magildan temple.");
  SetProperty("magic","You have a vague feeling those thorns aren't "
    "full of medicine.");
 }

