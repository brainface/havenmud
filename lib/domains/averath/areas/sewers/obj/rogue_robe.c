// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("black hooded robe");
  SetShort("a black hooded robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({ "black", "hooded" }) );
  SetLong(
    "This black robe is reasonably well made, with a large hood "
    "on the collar. Clearly designed to keep the wearer reasonably "
    "warm, it offers minimal protection. However, it is completely black, "
    "which could be of some use to someone who wished to blend into the "
    "shadows."
  	);
  SetMass(100);
  SetValue(50);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);  
  SetDamagePoints(700);
  SetSize(SIZE_MEDIUM);
}