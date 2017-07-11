#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("flimsy stick");
   SetShort("a flimsy stick");
   SetId( ({ "stick" }) );
   SetAdjectives( ({ "flimsy" }) );
   SetLong("This stick seems to be rather fresh, but that only makes "
           "it flimsy and springy.");
   SetMass(2);
   SetValue(7);
   SetVendorType(VT_WEAPON);
   SetClass(5);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(150);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "weapon smithing" : 1,
                       "wood working" : 1,
                  ]) );
}


/* Approved by Zaxan on Sat Jan 17 02:49:54 1998. */
