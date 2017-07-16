#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sword");
   SetShort("a decorative sword");
   SetId( ({ "sword" }) );
   SetAdjectives( ({ "decorative" }) );
   SetLong("Small jewels are embedded in the hilt in a simple "
           "pattern that is worth a good deal of gold.  The "
           "sword blade itself is of a strong metal and could "
           "be sharpened to a slicing edge.");
   SetMass(53);
   SetValue(650);
   SetClass(16);
   SetVendorType(VT_WEAPON);
   SetWeaponType("slash");
   SetDamageType(SLASH);
   SetDamagePoints(425);
   SetMaterial( ({ "metal","natural" }) );
   SetRepairDifficulty(25);
   SetRepairSkills( ([
                       "weapon smithing" : 2,
                       "metal working" : 2,
                       "natural working" : 0,
                  ]) );
}