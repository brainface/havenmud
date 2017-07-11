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
    SetLong(
      "This is a set a daemon bone armour. Many daemons died to create this armour "
      "which looks like a skeleton of a daemon. The armour provides protection "
      "from injury and flexibility of free movement for the wearer.");
    SetMass(800);
    SetMaterial( ({
      "natural",
      "leather"
      }) );
    SetRepairDifficulty(50);
    SetArmourClass(ARMOUR_NATURAL);
    SetWarmth(10);
    SetSize(SIZE_MEDIUM);
    SetValue(2500);
    SetDamagePoints(2000);
    SetArmourType(A_BODY_ARMOUR);
    SetVendorType(VT_ARMOUR);
}