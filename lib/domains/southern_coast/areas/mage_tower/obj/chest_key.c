#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetId( ({ "key", "chest_key" }) );
    SetKeyID("chest_key");
    SetAdjectives( ({ "small","obsidian"}) );
    SetShort("a small obsidian key");
    SetLong("The small obsidian key is made to unlock some kind of door.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("natural");
    SetVendorType(VT_TREASURE);
    SetDisableChance(2);
}
 
