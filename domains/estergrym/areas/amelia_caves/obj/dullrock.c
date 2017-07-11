// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetKeyName("rock");
   SetId( ({ "rock", }) );
   SetAdjectives( ({ "semisharp" }) );
   SetShort("a semisharp rock");
   SetLong("The semisharp rock is dark.  It could be used in a "
           "hacking manner.");
   SetMass(150);
   SetValue(3);
   SetVendorType(VT_WEAPON);
   SetClass(3);
   SetWeaponType("hack");
   SetDamageType(SLASH);
   SetDamagePoints(300);
   SetDestroyOnSell(1);
   SetWield("The semisharp rock fits comfortably in your hand.");
   SetMaterial( ({ "natural" }) );
}
