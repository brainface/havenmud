#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("light longsword");
   SetShort("a light longsword");
   SetId( ({ "longsword","sword" }) );
   SetAdjectives( ({ "long","light" }) );
   SetLong("The sword is long, as most longswords are, but it is "
           "thinner and less heavy as well.  It's edge is quite fine.");
   SetMass(70);
   SetClass(12);
   SetValue(1520);
   SetVendorType(VT_WEAPON);
   SetDamageType(SLASH);
   SetWeaponType("slash");
   SetDamagePoints(975);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(11);
   SetRepairSkills( ([
                       "weapon smithing" : 2,
                       "metal working" : 2,
                  ]) );
}