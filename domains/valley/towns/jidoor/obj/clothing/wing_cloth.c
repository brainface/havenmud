/*
 * A leather wingguard for harpies
 *
 *
 */

#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("silk winglet");
  SetId(( {"winglet"} ));
  SetShort("a black silk winglet");
  SetAdjectives( ({"black", "silk"}) );
  SetLong(
    "This tiny thimble of silk is shaped to cover the tips of a sprite's "
    "wings, the thin material adding very little weight. Red flames of silver "
    "are embroidered boldly on the surface. It's probably in style somewhere. "   
  );
  SetArmourType(A_WING);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(2000);
  SetMass(10);
  SetMaterial("textile");
  SetRepairDifficulty(10);
    SetSize(SIZE_VERY_SMALL);
  SetValue(500);
  SetVendorType(VT_ARMOUR);
  SetWarmth(5);
  SetWear("You pull the tiny bit of silk snuggly over your wingtip.");
}

