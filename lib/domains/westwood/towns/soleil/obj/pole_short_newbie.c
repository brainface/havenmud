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
   SetValue(0);
   SetClass(13);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetDamagePoints(900);
   SetVendorType(VT_WEAPON);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(10);
}
