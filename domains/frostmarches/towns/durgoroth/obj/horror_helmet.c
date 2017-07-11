#include <armour_types.h>
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;
static void create() {
    armour::create();
    SetKeyName("helmet");
    SetId( ({ "helmet", "daemonic helmet" }) );
    SetAdjectives( ({ "daemonic", "daemon" }) );
    SetShort("a daemonic helmet");
    SetWarmth(2);
    SetLong("This is a large helmet with holes to"
            " accommodate daemon horns.");
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
          "metal working" : 8,
          "armour smithing" : 9,
          ]) );
    SetRepairDifficulty(40);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_HEAVY_PLATE);
    SetDamagePoints(2500);
    SetMass(200);
    SetArmourType(A_HELMET);
    SetSize(SIZE_LARGE);
    SetValue(1000);
}
