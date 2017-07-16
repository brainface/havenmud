#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("short sword");
    SetId(({ "sword" }) );
    SetAdjectives( ({ "rusty", "short", }) );
    SetShort("a rusty short sword");
    SetLong("This is a standard enough short sword, though it "
            "appears to have become rusted due to age and dampness.");
    SetMass(55);
    SetValue(15);
    SetVendorType(VT_WEAPON);
    SetClass(12);
    SetDamageType(SLASH);
    SetWeaponType("slash");
}
