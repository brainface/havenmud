/* 5/03 Libitina / deer pelt / newbie vale */


#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("pelt");

    SetShort("a deer's pelt");
    SetLong("This soft brown pelt of short fur was once worn by a deer.");
    SetId( ({ "pelt" }) );
    SetAdjectives( ({"deer", "deers", "deer's"}) );
    SetValue(8);
    SetMass(10);
    SetVendorType(VT_FUR);
    SetMaterial("leather");
}
