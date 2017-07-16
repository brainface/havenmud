// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("antler");
   SetShort("a massive elk antler");
   SetId(({ "antler" }) );
   SetAdjectives( ({ "massive","elk" }) );
   SetLong("The branches of the antler intertwine like the tangled web of lies "
           "told by all politicians.  A deep chocolate shade of brown, the "
           "antler functions as a bashing weapon.");
   SetMass(50);
   SetValue(200);
   SetVendorType(VT_WEAPON|VT_TREASURE);
   SetDamagePoints(300);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
//   SetMaterial( ({ "natural" }) );
//   SetRepairDifficulty(5);
//   SetRepairSkills( ([
//                       "metal working" : 0,
//                       "weapon smithing" : 0,
//                  ]) );
   SetClass(15);
}
