#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    key::create();
    item::create();
    SetKeyName("key");
    SetKeyID("rusty key");
    SetId( ({ "rusty key", "key" }) );
    SetAdjectives( ({ "rusty" ,"large" }) );
    SetShort("a rusty key");
    SetLong("The key is quite large and rusted through the passage of time,"
       " with no distinguishing features.");
    SetMass(10);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetDestroyOnSell(1);
    SetVendorType(VT_TREASURE);
    SetDisableChance(90);
}

/** Approved by Laoise at Wed Jul 14 23:29:49 2004. **/
