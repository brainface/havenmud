#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("broad axe");
  SetId( ({ "axe", }) );
  SetShort("a sharp broad axe");
  SetAdjectives( ({ "sharp", "broad" }) );
  SetLong("A sharp broad axe head sits atop a three foot staff.");
  SetMass(200); 
  SetValue(150);
  SetDamagePoints(900);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(15);
  SetVendorType(VT_WEAPON);
}
