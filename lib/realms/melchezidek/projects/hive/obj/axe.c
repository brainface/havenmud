#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("axe");
   SetShort("a heavy one-handed axe");
   SetId( ({ "axe" }) );
   SetAdjectives( ({ "heavy", "one-handed", "one handed" }) );
   SetLong("This heavy axe is made with a stone grip and a large metal blade"
           " that is slightly dented and worn from excessive use but looks"
           " like an extremely servicable weapon.");
   SetMass(200);
   SetValue(750);
   SetDamagePoints(1000);
   SetVendorType(VT_WEAPON);
   SetWeaponType("hack");
   SetDamageType(SLASH);
   SetClass(18);
   SetMaterial( ({ "metal", "natural" }) );
   SetRepairDifficulty(20);
   SetRepairSkills( ([
                       "weapon smithing" : 5,
                       "metal working" : 5,
                       "natural working" : 5,
                  ]) );
}
