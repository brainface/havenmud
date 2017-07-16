// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("knife");
   SetShort("a blue-handled knife");
   SetId(({ "knife" }) );
   SetAdjectives( ({ "blue-handled","shark" }) );
   SetLong("The dark blue handle of this knife is shaped like a shark, "
           "molded with plenty of space to grip easily.  The blade is "
           "a large, strong tooth.");
   SetMass(3);
   SetValue(200);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(500);
   SetWeaponType("knife");
   SetDamageType(SLASH);
   SetClass(20);
}
