// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("driftwood");
   SetShort("a piece of driftwood");
   SetId(({ "driftwood","wood" }) );
   SetAdjectives( ({ "piece of","drift" }) );
   SetLong("This sturdy piece of driftwood serves as a blunt club. ");
   SetMass(5);
   SetValue(10);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(400);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetClass(8);
}
