#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key", "prince_key" }) );
    SetKeyID("prince_key");
    SetAdjectives( ({ "small","wooden"}) );
    SetShort("a small wooden key");
    SetLong("The small wooden key appears that it would open a lock.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("natural");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}


