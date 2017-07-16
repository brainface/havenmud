#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("walking stick");
   SetShort("a walking stick");
   SetId( ({ "stick","pole" }) );
   SetAdjectives( ({ "walking" }) );
   SetLong("The stick is long and straight and solid, making it useful "
           "for walking.");
   SetMass(180);
   SetValue(100);
   SetDamagePoints(300);
   SetVendorType(VT_WEAPON);
   SetClass(10);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(6);
   SetRepairSkills( ([
                       "wood working" : 2,
                       "weapon smithing" : 1,
                  ]) );
}
