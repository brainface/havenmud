#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("crossbow");
   SetShort("a plain crossbow");
   SetId( ({ "crossbow","bow" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("This plain crossbow looks efficient, "
           "but not particularly powerful or "
           "damaging.");
   SetMass(30);
   SetClass(7);
   SetVendorType(VT_WEAPON);
   SetValue(25);
   SetDamagePoints(250);
   SetDamageType(PIERCE);
   SetWeaponType("projectile");
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "weapon smithing" : 0,
                       "wood working" : 0,
                  ]) );
}
