#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key" }) );
    SetKeyID("circle_key");
    SetAdjectives( ({ "small","cast iron", "iron"}) );
    SetShort("a small cast iron key");
    SetLong("The small cast iron skeleton key has a circle engraved on it.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
