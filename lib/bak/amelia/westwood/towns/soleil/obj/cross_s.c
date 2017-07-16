#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("crossbow");
   SetShort("a small crossbow");
   SetId( ({ "crossbow","bow" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("This small crossbow is the weapon of a skilled ranger.  It "
           "has little size to it, but the compactness is merely to "
           "allow one more easy movement.  It is still strong and would "
           "snap off nasty arrows if one were to wield it.");
   SetMass(25);
   SetValue(190);
   SetWeaponType("projectile");
   SetDamageType(PIERCE);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(930);
   SetMaterial( ({ "wood","natural" }) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "wood working" : 3,
                       "natural working" : 3,
                       "weapon smithing" : 4,
                  ]) );
   SetClass(17);
}
