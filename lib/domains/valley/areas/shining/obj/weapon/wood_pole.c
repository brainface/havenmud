#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("solid oak pole");
   SetShort("a solid oak pole");
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "solid","oak" }) );
   SetLong("The pole is made of solid oak. It has a lot of intricate "
           "carvings cut into it. It been coated with a black lacquer. ");
   SetClass(20);
   SetMass(100);
   SetVendorType(VT_WEAPON);
   SetValue(1000);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetDamagePoints(3000);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "wood working" : 10,
                       "weapon smithing" : 10,

                  ]) );
}
