#include <lib.h>
#include <vendor_types.h>
inherit LIB_POLE;
 
static void create() {
    pole::create();
    SetKeyName("willow pole");
  SetMaterials( ({ "wood" }) );
    SetId( ({ "pole", "willow pole", "willow"  }) );
    SetAdjectives( ({ "willow", "flexable" }) );
    SetShort("a willow pole");
    SetLong("It is a flexable willow fishing pole with "
            "a long string at the end of it.");
    SetClass(5);
    SetValue(10);
    SetMass(30);
    SetVendorType(VT_TREASURE | VT_FISHING);
    SetStrength(90);
    SetChance(50);
}

static mixed AddSave(mixed *var) {
    return pole::AddSave(var);
}
