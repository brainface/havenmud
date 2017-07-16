#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a steel longsword");
        SetLong("The finely crafted steel blade of this "
                "sword gleams in the light.");
        SetId( ({"sword", "longsword","steel","steel longsword",
                 "long"}) );
        SetClass(14);
        SetDamagePoints(1800);
        SetValue(360);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        SetKeyName("sword");
	SetMass(175);
	SetVendorType(VT_WEAPON);
	SetAdjectives( ({"steel"}) );
}


