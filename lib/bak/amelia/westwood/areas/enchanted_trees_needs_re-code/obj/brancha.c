// Amelia@Haven

#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
#include <damage_types.h>

static void create() {
   item::create();
   SetKeyName("branch");
   SetShort("a normal branch");
   SetId( ({ "normal branch","branch" }) );
   SetAdjectives( ({ "normal" }) );
   SetLong("Some green and brown leaves hang to the edges of the branch.");
   SetMass(30);
   SetValue(15);
   SetVendorType(VT_WEAPON);
   SetClass(3);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(400);
   SetDestroyOnSell(1);
   SetMaterial("wood");
}
