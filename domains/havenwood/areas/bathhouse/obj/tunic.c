
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
 armour::create();
 SetKeyName("fine leather tunic");
 SetId("tunic");
 SetAdjectives( ({ "leather", "fine" }) );
 SetShort("a fine leather tunic");
 SetLong(
    "This tunic looks a bit worn on the hems, but altogether has "
    "been well maintained. The leather material has been well "
    "tanned to give the tunic a rather pricey appearance, even "
    "if it is not dyed."
  );
 SetMass(50);
 SetArmourClass(ARMOUR_LEATHER);
 SetValue(50);
 SetVendorType(VT_ARMOUR);
 SetArmourType(A_SHIRT);
 SetDamagePoints(125);
 // SetProtection(SLASH, 2);
 // SetProtection(PIERCE, 5);
 SetMaterial( ({ "leather" }) );
 SetRepairDifficulty(5);
 SetSize(SIZE_MEDIUM);
 SetWarmth(10);
 }
