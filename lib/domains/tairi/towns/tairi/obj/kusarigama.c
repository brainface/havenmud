/* a whip chain slashing blade */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("kusari-gama");
  SetShort("a small axe attached to a chain");
  SetId( ({ "axe", "kusari-gama", "gama" }) );
  SetAdjectives( ({ "small", "kusari" }) );
  SetLong("A kusari-gama is a small and deadly axe attached "
          "to a short chain which can be used to extend the reach "
          "of the razor-sharp blade.");
  SetClass(18);
  SetDamagePoints(1200);
  SetMass(65);
  SetValue(120);
  SetMaterial("metal");
  SetWeaponType("projectile");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
}
