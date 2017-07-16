// mahkefel 20101117
// viking axe
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("broad axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({ "broad" }) );
  SetShort("a steel broad axe");
  SetLong(
    "This crescent-bladed axe could penetrate "
    "chainmail or steel plate with a strong "
    "enough swing, and its light wooden shaft "
    "provides excellent balance."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(2500);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetKeyName("broad axe");
  SetMass(350);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

