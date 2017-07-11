
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
 armour::create();
 SetKeyName("towel");
 SetId("towel");
 SetAdjectives( ({ "cloth", "white", "long" }) );
 SetShort("a white cloth towel");
 SetLong(
    "This towel shows signs of wear, but appears to be clean. "
    "About six feet long, this towel should cover even the "
    "fattest of people."
  );
 SetMass(20);
 SetValue(10);
 SetVendorType(VT_CLOTHING);
 SetArmourClass(ARMOUR_CLOTH);
 SetArmourType(A_BELT);
 SetDamagePoints(50);
 SetMaterial( ({ "textile" }) );
 SetRepairDifficulty(5);
 SetSize(SIZE_MEDIUM);
 SetWarmth(8);
 }
