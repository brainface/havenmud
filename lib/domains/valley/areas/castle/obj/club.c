#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("huge club");
   SetShort("a huge club");
   SetId( ({ "club" }) );
   SetAdjectives( ({ "huge","thick","large" }) );
   SetLong("Strong wood, difficult to break, makes up this club "
           "of an unusual size.");
   SetMass(125);
   SetClass(19);
   SetValue(2000);
   SetVendorType(VT_WEAPON);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(1100);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "wood working" : 4,
                       "weapon smithing" : 3,
                  ]) );
   SetHands(2);
}   