// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("sword");
   SetShort("a black longsword");
   SetId(({ "longsword","sword" }) );
   SetAdjectives( ({ "black" }) );
   SetLong("The longsword is black, both hilt and blade, so deep in "
           "color that nothing reflects from it.");
   SetMass(35);
   SetValue(100);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(900);
   SetWeaponType("slash");
   SetDamageType(SLASH);

   SetClass(20);
}
