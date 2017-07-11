#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
 armour::create();
 SetKeyName("black dress");
 SetId("dress");
 SetAdjectives( ({ "black", "loose" }) );
 SetShort("a loose black dress");
 SetLong(
    "This dress appears to be made to get out of. The shoulder "
    "straps are made of a flexible material, but dyed to match "
    "the rest of the dress. Being cut loosely, this dress looks "
    "like it would serve better as a blanket than a piece of "
    "clothing."
  );
 SetMass(60);
 SetArmourClass(ARMOUR_CLOTH);
 SetValue(40);
 SetSize(SIZE_MEDIUM);
 SetVendorType(VT_CLOTHING);
 SetArmourType(A_BODY_ARMOUR);
 SetDamagePoints(50);
 SetMaterial( ({ "textile" }) );
 SetRepairDifficulty(5);
 SetWarmth(15);
 }

/** Approved by Laoise at Wed Jul 14 22:11:38 2004. **/
