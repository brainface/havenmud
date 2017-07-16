#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("short pole");
   SetShort("a short pole");
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "short" }) );
   SetLong("Dense wood forms the shape of a short pole to create a "
           "sturdy weapon.");
   SetMass(40);
   SetValue(300);
   SetClass(16);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetDamagePoints(1500);
   SetVendorType(VT_WEAPON);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "wood working" : 5,
                       "weapon smithing" : 5,
                  ]) );
}
