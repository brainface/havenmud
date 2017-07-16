/* 5/03 Libitina / squirrel's tail */


#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("tail");
    SetShort("a tail");
    SetLong("Long and furry, this squirrel's tail could probably "
      "be useful in some way.");
    SetId( ({ "tail" }) );
    SetValue(3);
    SetMass(3);
    SetVendorType(VT_FUR);
    SetMaterial("leather");
}
