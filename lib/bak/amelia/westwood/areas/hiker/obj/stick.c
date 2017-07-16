#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("fat stick");
   SetShort("a fat stick");
   SetId( ({ "stick" }) );
   SetAdjectives( ({ "fat" }) );
   SetLong("The stick is thick and fat, but it looks as if it has "
           "started to decompose.");
   SetMass(50);
   SetValue(4);
   SetVendorType(VT_WEAPON);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetClass(4);
   SetDamagePoints(70);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "wood working" : 1,
                  ]) );
}
