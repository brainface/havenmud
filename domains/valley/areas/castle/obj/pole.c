#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("wooden pole");
   SetShort("a wooden pole");
   SetId( ({ "pole","wood" }) );
   SetAdjectives( ({ "wooden","wood" }) );
   SetLong("An indentation in the wood shows where it has been held "
           "before.  Other than that, the wood is solid and strong.");
   SetMass(175);
   SetValue(1020);
   SetClass(15);
   SetDamagePoints(670);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetVendorType(VT_WEAPON);
   SetHands(2);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(11);
   SetRepairSkills( ([
                       "weapon smithing" : 2,
                       "wood working" : 2,
                  ]) );
}
