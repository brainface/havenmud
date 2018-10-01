#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetShort("a %^CYAN%^sizzling%^RESET%^ black bladed knife");
  SetLong(
     "This knife has been forged with an unknown black "
     "metal. It has been imbued with an electric blessing "
     "which provides some light."
  );
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "black","bladed" }) );
  SetClass(35);
  SetDamagePoints(1000);
  SetValue(150);
  SetWeaponType("slash");
  SetDamageType(SHOCK);
  SetKeyName("knife");
  SetMass(10);
  SetRadiantLight(2);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
