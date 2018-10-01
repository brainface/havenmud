#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("breastplate");
    SetId( ({ "breastplate" }) );
    SetAdjectives( ({ "dwarven", "sturdy", "suit of" }) );
    SetShort("a brightly polished breastplate");
    SetLong("The breastplate is made of the finest mithril forged into "
            "thick armour plate. Bright swirls of a bluish hue make the "
            "armour look warped, as if it contained something of great heat at "
            "some point. The breastplate is fairly light while still being "
            "incredibly strong.");
    SetMass(350);
    //SetProperty();
    SetVendorType(VT_ARMOUR);
    SetMaterial( ({ "mithril" }) );
    SetRepairDifficulty(400);
    SetValue(50000);
    SetArmourClass(ARMOUR_PLATE);
    SetDamagePoints(3500);
    SetArmourType(A_ARMOUR);
    SetSize(SIZE_MEDIUM);
}
