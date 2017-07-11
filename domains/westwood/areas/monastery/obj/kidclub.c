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
   SetLong("The fat stick is very blunt, but doesn't appear to be "
           "useful in any special way.");
   SetMass(45);
   SetClass(3);
   SetValue(3);
   SetDamageType(BLUNT);
   SetWeaponType("blunt");
   SetVendorType(VT_WEAPON);
   SetDamagePoints(250);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "wood working" : 1,
                       "weapon smithing " : 1,
                  ]) );
}