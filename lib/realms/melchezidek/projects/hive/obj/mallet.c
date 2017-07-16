#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("mallet");
   SetShort("a small stone mallet");
   SetId( ({ "mallet" }) );
   SetAdjectives( ({ "small", "stone", }) );
   SetLong("This is a small stone mallet used for various tasks that involve"
           " bashing and pounding.");
   SetMass(200);
   SetValue(250);
   SetDamagePoints(200);
   SetVendorType(VT_WEAPON);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetClass(12);
   SetMaterial( ({ "metal", "natural" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "weapon smithing" : 5,
                       "natural working" : 5,
                  ]) );
}

