#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("bee stinger");
   SetShort("a bee stinger");
   SetId( ({ "stinger" }) );
   SetAdjectives( ({ "bee","small" }) );
   SetLong("The small stinger is pointed at the tip, and it looks "
           "like a little poison might remain there.");
   SetMass(3);
   SetValue(5);
   SetVendorType(VT_TREASURE|VT_WEAPON);
   SetDamagePoints(700);
   SetDamageType(POISON|PIERCE);
   SetWeaponType("knife");
   SetClass(8);
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "natural working" : 1,
                       "weapon smithing" : 1,
                  ]) );
}
