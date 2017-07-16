/* 5/03 Libitina / fox pelt / newbie vale */


#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("pelt");
    SetShort("a fox's pelt");
    SetAdjectives( ({"fox", "foxs", "fox's"}) );
    SetLong("The thick red fur of this pelt once belonged to a fox.");
    SetId( ({ "pelt" }) );
    SetValue(9);
    SetMass(9);
    SetVendorType(VT_FUR);
    SetMaterial("leather");
}
