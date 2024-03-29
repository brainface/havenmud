#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
	::create();
    SetKeyName("gray robe");
    SetShort("a grey robe");
    SetId( ({ "robe" }) );
    SetAdjectives( ({ "grey" }) );
    SetLong("The grey robe is nothing out of the ordinary, but it is "
           "a fairly well made article of clothing.  The robe is rather "
           "bulky and heavy as well. A small amount of embroidery is "
           "visible around the trim of the collar, the cuffs and the "
           "brocade. It is a long flowing garment and would likely offer a "
           "slight amount of protection against the cold.");
    SetMaterial("textile");
    SetWarmth(25);
    SetSize(SIZE_MEDIUM);
    SetRepairDifficulty(10);
    SetMass(80);
    SetValue(75);
    SetDamagePoints(750);
    SetVendorType(VT_ARMOUR);
    SetArmourType(A_BODY_ARMOUR);
    SetArmourClass(ARMOUR_CLOTH);
}
