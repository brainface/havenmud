#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key", "casket_key" }) );
    SetKeyID("casket_key");
    SetAdjectives( ({ "small","brass"}) );
    SetShort("a small brass key");
    SetLong("The small brass key is made to unlock something.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
