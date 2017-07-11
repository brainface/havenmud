

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key" }) );
    SetKeyID("herm_key");
    SetAdjectives( ({ "small","iron"}) );
    SetShort("a small iron key");
    SetLong("This is a small iron key with some runes etched upon it.");
    SetMass(10);
    SetValue(0);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
