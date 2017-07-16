/*coded by AtRuS 07-11-99*/
// typoes fixed by Zeratul
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
        item::create();
        SetShort("a meat cleaver");
          SetLong("The rugged blade of the cleaver "
                "looks like it would rip through any "
                "armour and leave gashes of festering "
                "disease and infection. It has a hilt of  "
                "long, fine cut ivory.");
        SetId( ({"cleaver","meat cleaver"}) );
        SetClass(15);
        SetDamagePoints(500);
        SetValue(500);
        SetWeaponType("hack");
        SetDamageType(SLASH);
        SetKeyName("meat cleaver");
        SetMass(50);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "ivory" }) );
        SetHands(1);
      	SetMaterial( ({
      		"natural",
      		"metal",
      		}) );
      	SetRepairDifficulty(5);
      		
}
