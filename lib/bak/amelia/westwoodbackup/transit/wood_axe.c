#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a wood axe");
        SetLong("An axe like this leans up against every "
                "woodsman's house in Kailie" );
        SetId( ({"wood", "wood axe","axe"}) );
        SetClass(9);
        SetDamagePoints(750);
        SetValue(180);
        SetWeaponType("hack");
        SetDamageType(SLASH);
        SetKeyName("axe");
	SetMass(75);
	SetVendorType(VT_WEAPON);
	SetAdjectives( ({ "wood" }) );
}
