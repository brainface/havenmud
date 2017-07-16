#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;
static void create() {
    armour::create();
    SetKeyName("shield");
    SetId( ({ "large black shield", "black shield", "large shield", "large" }) );
    SetShort("large black shield");
    SetLong("a large black shield");
    SetLong("This shield is built from 2 round slabs of metal, fastened "
    "around several layers of leather, hide, and cloth.  It provides "
    "excellent protection for a while but is easily broken.");
    SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
    SetValue(150);
    SetMass(100);
    SetDamagePoints(600);
    // SetProtection(SLASH, 5);
    // SetProtection(BLUNT, 7);
    // SetProtection(PIERCE, 3);
    SetArmourType(A_SHIELD);
    SetSize(SIZE_LARGE);
    SetMaterial( ({ "metal", "leather" }) );
    SetWarmth(0);
    SetRepairSkills( ([
    "metal working" : 4,
    "leather working" : 4,
    "armour smithing" : 4,
]) );
    SetRepairDifficulty(25);
}
