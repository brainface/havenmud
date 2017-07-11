//
// filename: doorkey1
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
    SetKeyID("doorkey1");
    SetAdjectives( ({ "small","iron"}) );
    SetShort("a small iron key");
    SetLong("The small iron key is made to unlock some kind of door.");
    SetMass(1);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
