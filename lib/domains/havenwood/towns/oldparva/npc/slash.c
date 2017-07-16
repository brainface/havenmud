#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sword");
   SetShort("a small sword");
   SetId( ({ "sword" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("The sword is very small and doesn't weigh much.  "
           "It looks worthless, but could be useful for fighting.");
   SetMass(15);
   SetValue(0);
   SetClass(15);
   SetVendorType(VT_WEAPON);
   SetWeaponType("slash");
   SetDamageType(SLASH);
   SetDamagePoints(150);
   SetMaterial( ({ "metal" }) );
   SetProperty("history","This is one of the free items given "
               "to newbies in Parva.");
}
