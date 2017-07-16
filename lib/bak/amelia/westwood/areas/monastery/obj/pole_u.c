#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("hard wood pole");
   SetShort("a hard wooden pole");
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "hard","wood","wooden" }) );
   SetLong("The pole is made of a hard wood, and has been strengthened "
           "by compression, making it more dense.");
   SetClass(19);
   SetMass(200);
   SetVendorType(VT_WEAPON);
   SetValue(350);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetDamagePoints(900);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(20);
   SetRepairSkills( ([
                       "wood working" : 4,
                       "weapon smithing" : 4,
                  ]) );
}