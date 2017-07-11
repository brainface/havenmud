
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
 armour::create();
 SetKeyName("brown leather boots");
 SetId("boots");
 SetAdjectives( ({ "leather", "brown", "pair",
    "pair of" }) );
 SetShort("a pair of brown leather boots");
 SetLong(
    "These boots are worn and ratty. The heels of the boots "
    "are in need of some serious repair."
  );
 SetMass(30);
 SetArmourClass(ARMOUR_LEATHER);
 SetProperty("multiples",1);
 SetValue(10);
 SetVendorType(VT_CLOTHING);
 SetArmourType(A_BOOT);
 SetDamagePoints(30);
 SetMaterial( ({ "leather" }) );
 SetRepairDifficulty(5);
 SetSize(SIZE_MEDIUM);
 SetWarmth(10);
 }
