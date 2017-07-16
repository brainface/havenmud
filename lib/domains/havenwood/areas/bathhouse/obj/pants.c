#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
 armour::create();
 SetKeyName("brown leather pants");
 SetId("pants");
 SetAdjectives( ({ "leather", "brown", "pair",
    "pair of" }) );
 SetShort("a pair of brown leather pants");
 SetLong(
    "These pants sport patches of all colors and "
    "show signs of wear on every portion of unpatched "
    "leather. The pants are big and rather baggy, but "
    "not too much larger than a normal pair of pants "
    "made for a medium sized person."
  );
 SetMass(60);
 SetArmourClass(ARMOUR_LEATHER);
 SetValue(10);
 SetVendorType(VT_CLOTHING);
 SetArmourType(A_PANTS);
 SetDamagePoints(70);
 SetMaterial( ({ "leather" }) );
 SetRepairDifficulty(5);
 SetSize(SIZE_MEDIUM);
 SetWarmth(10);
 }
