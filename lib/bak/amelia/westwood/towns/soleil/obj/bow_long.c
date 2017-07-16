#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sturdy long bow");
   SetShort("a sturdy long bow");
   SetId( ({ "bow" }) );
   SetAdjectives( ({ "sturdy","long" }) );
   SetLong("Light wooden and natural materials make the sturdy long "
           "bow.");
   SetClass(17);
   SetValue(400);
   SetMass(50);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(1200);
   SetWeaponType("projectile");
   SetDamageType(PIERCE);
   SetMaterial( ({ "wood","natural" }) );
   SetRepairDifficulty(35);
   SetRepairSkills( ([
                       "wood working" : 7,
                       "natural working" : 7,
                       "weapon smithing" : 7,
                  ]) );
   SetHands(2);
}
