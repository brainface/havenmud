/* armour for maraliths
 * About 1 tick better than kelans on all fronts
 * but heavier.
 */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("breastplate");
    SetId( ({ "breastplate" }) );
    SetShort("a bronze breastplate");
    SetAdjectives( ({"bronze","heavy"}) );
    SetLong("This heavy bronze breastplatehas been marked by seemingly "
            "ages of combat. Its surface is scarred by countless dents "
            "and slashes, but it is apparently still quite sound. The "
            "dense metal would provide excellent protection for the "
            "torso, but the sides are covered merely by connecting "
            "leather straps, to allow freedom of movement."
    );
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(80);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_HEAVY_PLATE);
    SetValue(5000);
    SetMass(600);
    SetDamagePoints(5000);
    SetArmourType(A_ARMOUR);  
    SetWear("The immense weight of the breastplate pulls on your shoulders.");
}

