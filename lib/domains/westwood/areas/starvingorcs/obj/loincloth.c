#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("loincloth");
    SetSize(SIZE_LARGE);
    SetId( ({ "loincloth", }) );
    SetAdjectives( ({ "dirty", }) );
    SetShort("a dirty loincloth");
    SetLong("Gravy and dirty stains are rubbed into the large-sized loincloth.");
    SetVendorType(VT_CLOTHING);
    SetMass(10);
    SetValue(5);
    SetArmourClass(ARMOUR_CLOTH);
    SetDamagePoints(80);
    // SetProtection(HEAT, 1);
    // SetProtection(COLD, 1);
    SetArmourType(A_BELT);
    SetWarmth(3);
    SetMaterial("textile");
    SetRepairDifficulty(5);
   
}
