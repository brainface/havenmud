#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("skinny stick");
   SetShort("a skinny stick");
   SetId( ({ "stick" }) );
   SetAdjectives( ({ "skinny" }) );
   SetLong("The skinny stick looks like a child's toy, used in playing "
           "fighting games as a pole.");
   SetMass(35);
   SetClass(3);
   SetValue(3);
   SetDamageType(BLUNT);
   SetWeaponType("pole");
   SetVendorType(VT_WEAPON);
   SetDamagePoints(150);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "wood working" : 1,
                       "weapon smithing " : 1,
                  ]) );
}