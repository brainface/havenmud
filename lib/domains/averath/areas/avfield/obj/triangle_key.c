#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key" }) );
    SetKeyID("triangle_key");
    SetAdjectives( ({ "small","mithril"}) );
    SetShort("a small mithril key");
    SetLong("The small mithril skeleton key has a triangle engraved on it.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
