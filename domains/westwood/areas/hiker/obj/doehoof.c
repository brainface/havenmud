#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("deer hoof");
   SetShort("a deer hoof");
   SetId( ({ "hoof" }) );
   SetAdjectives( ({ "deer","solid","blunt","doe" }) );
   SetLong("The hoof is solid and blunt.  It is not very large, "
           "however.");
   SetMass(50);
   SetValue(10);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(150);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetClass(5);
   SetMaterial("natural");
   SetRepairDifficulty(80);
   
   
}
