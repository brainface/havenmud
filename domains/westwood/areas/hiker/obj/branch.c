#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("splitting branch");
   SetShort("a splitting branch");
   SetId( ({ "branch" }) );
   SetAdjectives( ({ "splitting","thick" }) );
   SetLong("The branch is thick in the main part, but splits off into "
           "thin whip-like strands with pointy ends.");
   SetMass(120);
   SetValue(15);
   SetVendorType(VT_WEAPON);
   SetWeaponType("blunt");
   SetDamageType(PIERCE|SLASH|BLUNT);
   SetHands(2);
   SetClass(4);
   SetDamagePoints(325);
   SetMaterial("wood");
   SetRepairDifficulty(80);
}
