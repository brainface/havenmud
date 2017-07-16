#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rune sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "rune", "encrusted" }) );
  SetShort("a rune encrusted sword");
  SetLong(
    "This long sword is formed from black metal, including the blade and "
    "cross-guard. The grip is covered with intricately wrapped black leather "
    "which blends into the metal of the sword. The pommel is formed of a "
    "carved claw gripping a metal sphere which seems to shine with intricate "
    "patterns in its inky depths. Runes of battle are etched deeply in to "
    "the blade and seem to give off a faint dark glow."
  );
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(18);
  SetValue(2500);
  SetMass(200);
  SetMaterials( ({
    "metal"
  }) );
}
