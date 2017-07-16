#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("knife");
    SetId(({ "knife" }) );
    SetAdjectives( ({ "balanced" }) );
    SetShort("a well balanced knife");
    SetLong("This is a long and well balanced knife. Unlike most "
            "things in the sewers, this knife is well kept and "
            "very sharp.");
    SetMass(45);
    SetValue(25);
    SetVendorType(VT_WEAPON);
    SetClass(13);
    SetDamageType(SLASH);
    SetWeaponType("knife");
}
