#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
  key::create();
    SetKeyName("key");
  SetKeyID("STDKEY001");
  SetId( ({ "key" }) );
    SetAdjectives( ({ "small","metal"}) );
    SetShort("a small metal key");
    SetLong("The small metal key is made to unlock some kind of door.");
    SetMass(1);
    SetValue(15);
    SetDamagePoints(20);
    SetMaterial("metal");
    SetVendorType(VT_TREASURE);
    SetDisableChance(90);
}
