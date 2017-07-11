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
   SetLong("The pole is made of a hard wood, but is plain and "
           "has few other attributes.");
   SetClass(12);
   SetMass(150);
   SetVendorType(VT_WEAPON);
   SetValue(150);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetDamagePoints(650);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "wood working" : 2,
                       "weapon smithing" : 2,
                  ]) );
}