#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
 armour::create();
 SetKeyName("loincloth");
 SetId("loincloth");
 SetAdjectives( ({ "cloth", "white", "dirty" }) );
 SetShort("a dirty white loincloth");
 SetLong(
    "This loincloth looks rather questionable as if it "
    "has never seen the combination of water and soap. "
    "Grease and urine stains cover this once clean piece "
    "of cloth used to cover the genitals."
  );
 SetMass(20);
 SetValue(10);
  SetArmourClass(ARMOUR_CLOTH);
 SetSize(SIZE_MEDIUM);
 SetVendorType(VT_CLOTHING);
 SetArmourType(A_BELT);
 SetDamagePoints(50);
 SetWarmth(1);
 SetMaterial( ({ "textile" }) );
 SetRepairDifficulty(5);
 }
