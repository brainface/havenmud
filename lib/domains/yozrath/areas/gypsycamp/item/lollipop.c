#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "gypsycamp.h"

inherit LIB_ITEM;

static void create() {
    item::create();
     SetKeyName("lollipop");
     SetId( ({"lollipop"}) );
     SetShort("a lollipop");
     SetLong("This bright orange lollipop is extremely sticky "
             "and messy. It seems to still have some spittle "
             "on it.");
     SetVendorType(VT_WEAPON);
     SetDamagePoints(80);
     SetClass(5);
     SetValue(10);
     SetMass(5);
     SetWeaponType("blunt");
     SetDamageType(BLUNT);
}

