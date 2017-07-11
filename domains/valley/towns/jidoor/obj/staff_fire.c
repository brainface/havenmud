// mahkefel 2012
// elemental thing weapon
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ashen staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "ashen" }) );
  SetShort("an ashen staff");
  SetLong(
    "This long oaken staff seems to have been pulled directly "
    "from a campfire. Despite its charcoal like appearance, it "
    "seems quite sturdy still. Occasionally the charred ends "
    "glare with renewed fire."
  );
  SetHands(2);
  SetClass(20);
  SetWeaponType("pole");
  SetDamageType(BLUNT|HEAT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(800);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(15);

  SetProperty("history","This weapon was stolen from an elemental "
    "guarding the magildan temple.");
  SetProperty("magic","You have a vague feeling this staff might be hot "
    "in more ways than one.");
 }

