#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("bone armour");
    SetId("armour");
    SetAdjectives("bone");
    SetShort("a set of bone armour");
    SetLong("This is a set a crude but effective bone armour. Large bones "
            "have been tied onto leather.");
    SetMass(800);
    SetMaterial( ({
    	"natural",
    	"leather"
      }) );
    SetRepairDifficulty(15);
    SetArmourClass(ARMOUR_NATURAL);
    SetWarmth(10);
    SetSize(SIZE_LARGE);
    SetValue(150);
    SetDamagePoints(600);
    // SetProtection(SLASH, 8);
    // SetProtection(BLUNT, 6);
    // SetProtection(PIERCE, 3);
    SetArmourType(A_BODY_ARMOUR);
    SetVendorType(VT_ARMOUR);
}
