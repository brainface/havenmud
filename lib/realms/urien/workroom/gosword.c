#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a %^RED%^burning%^RESET%^ upper hell sword");
  SetLong(
     "This sword is best known as the weapon of choice from "
     "the upper demons of hell. Its black blade burns with "
     "pure magick."
  );
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "upper hell","hell" }) );
  SetClass(40);
  SetDamagePoints(5000);
  SetValue(2000);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("sword");
  SetMass(100);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
