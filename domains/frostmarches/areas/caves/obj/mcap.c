#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("metal cap");
    SetId("cap");
    SetAdjectives( ({"metal"}) );
    SetShort("a metal cap");
    SetLong("A typical metal cap that covers the top of a head.");
    SetMass(80);
    SetSize(SIZE_SMALL);
    SetValue(50);
    SetDamagePoints(600);
    // SetProtection(SLASH, 4);
    // SetProtection(BLUNT, 4);
    // SetProtection(PIERCE, 2);
    SetArmourType(A_HELMET);
    SetMaterial("metal");
    SetWarmth(0);
  SetArmourClass(ARMOUR_PLATE);
    SetRepairSkills( (["metal working" : 1,
                       "armour smithing" : 1,
                   ]) );
    SetRepairDifficulty(15);
    SetVendorType(VT_ARMOUR);
}
