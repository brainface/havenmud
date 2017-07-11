#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a plain knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("This plain knife looks efficient, "
           "but not particularly powerful or "
           "damaging.");
   SetMass(10);
   SetClass(7);
   SetVendorType(VT_WEAPON);
   SetValue(20);
   SetDamagePoints(200);
   SetDamageType(PIERCE);
   SetWeaponType("knife");
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "weapon smithing" : 0,
                       "metal working" : 0,
                  ]) );
}
