#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key" }) );
    SetKeyID("key35");
    SetAdjectives( ({ "large","iron"}) );
    SetShort("a large iron key");
    SetLong("The large iron key is made to unlock some kind of door.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
 
