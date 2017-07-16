//
// filename: throne1
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key" }) );
    SetKeyID("thronekey1");
    SetAdjectives( ({ "small","silver"}) );
    SetShort("a small silver key");
    SetLong("The small silver key is made to unlock some kind of door. The "
            "key itself is quite extravagent and regal.");
    SetMass(1);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
