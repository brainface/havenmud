#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create(string town, string owner) {
    item::create();
    key::create();
    if (!town || !owner) return;
    SetKeyName("key");
    SetId( ({ "key", town + "_" + owner + "_key" }) );
    SetAdjectives( ({ "small", "metal"}) );
    SetShort("a small metal key");
    SetLong("The small metal key is made to unlock some kind of chest.");
    SetMass(1);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(0);
    SetKeyID(town + "_" + owner + "_key");
}
