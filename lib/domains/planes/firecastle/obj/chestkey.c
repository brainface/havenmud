#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key", "chestkey" }) );
    SetKeyID("chestkey");
    SetAdjectives( ({ "small"}) );
    SetShort("a small key");
    SetLong("The small key is made to open a chest of some kind.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("natural");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
