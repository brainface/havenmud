#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
    item::create();
    digging::create();
    SetKeyName("spade");
    SetId("shovel", "spade");
    SetAdjectives( ({ "wooden" }) );
    SetShort("a large spade");
    SetMaterials( ({ "wood", "metal" }) );
    SetLong("This is a large spade with a wooden handle and a metal end. It"
            " is larger than a normal shove with a more pointed end.");
    SetMass(87);
    SetValue(200);
    SetProperty("farming item", 1);
    SetDamagePoints(400);
    SetClass(12);
}
