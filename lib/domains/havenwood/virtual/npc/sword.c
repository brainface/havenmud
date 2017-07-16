#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sword");
   SetShort("a plain sword");
   SetId( ({ "sword" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("This plain sword looks efficient, "
           "but not particularly powerful or "
           "damaging.");
   SetMass(45);
   SetClass(7);
   SetVendorType(VT_WEAPON);
   SetValue(30);
   SetDamagePoints(300);
   SetDamageType(SLASH);
   SetWeaponType("slash");
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "weapon smithing" : 0,
                       "metal working" : 0,
                  ]) );
}
