/* 5/03 Libitina / rabbit pelt / newbie vale */


#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("pelt");
    SetShort("a rabbit's pelt");
    SetAdjectives( ({"rabbits", "rabbit's", "rabbit"}) );
    SetLong("This pelt of gorgeous white fur was worn by a rabbit. "
      "It is flawless and soft.");
    SetId( ({ "pelt" }) );
    SetValue(8);
    SetMass(6);
    SetVendorType(VT_FUR);
    SetMaterial("leather");
}
