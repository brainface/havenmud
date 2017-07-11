#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
     item::create();
     SetKeyName("crystal ball");
     SetShort("a crystal ball");
     SetId( ({ "ball" }) );
     SetAdjectives( ({ "crystal" }) );
     SetLong("At first the crystal ball seems dark and "
             "unpenetrable to the naked eye. Then in an "
             "instant it clears and there appears something "
             "that an untrained eye will see as undeterminable.");
     SetMass(5);
     SetValue(0);
     SetVendorType(VT_TREASURE);
}


