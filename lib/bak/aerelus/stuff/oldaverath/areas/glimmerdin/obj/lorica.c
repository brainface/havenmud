#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("ringmail lorica");
    SetId( ({ "ringmail", "lorica", "armour"}) );
    SetAdjectives( ({ "ringmail", "thick", "heavy", "durable" }) );
    SetShort("a ringmail lorica");
    SetLong("This is a thick, heavy shirt of ringmail.  It was made "
            "in the forges of Glistendin, and it looks quite durable.");
    SetVendorType(VT_ARMOUR);
    SetArmourType(A_ARMOUR);
    SetArmourClass(ARMOUR_CHAIN);
  SetMaterials( ({"metal"}) );
    SetMass(450);
    SetValue(400);
    SetSize(SIZE_SMALL);
    SetDamagePoints(1200);
}
