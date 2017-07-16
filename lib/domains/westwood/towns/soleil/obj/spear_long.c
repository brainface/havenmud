#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("elongated spear");
   SetShort("an elongated spear");
   SetId( ({ "spear" }) );
   SetAdjectives( ({ "elongated" }) );
   SetLong("The spear stands high, invariably useful for poking at "
           "opponents from a distance, out of reach of their weapons.");
   SetMass(125);
   SetValue(275);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(750);
   SetWeaponType("pierce");
   SetDamageType(PIERCE);
   SetClass(14);
   SetMaterial( ({ "wood","metal" }) );
   SetRepairDifficulty(14);
   SetRepairSkills( ([
                       "weapon smithing" : 3,
                       "wood working" : 1,
                       "metal working" : 1,
                  ]) );
}
