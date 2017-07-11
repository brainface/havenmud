// Island
// Aerelus

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key", "island_key" }) );
    SetKeyID("island_key");
    SetAdjectives( ({ "small","rusty"}) );
    SetShort("a small rusty key");
    SetLong("This small key looks big enough to fit a chest or door.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("natural");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}