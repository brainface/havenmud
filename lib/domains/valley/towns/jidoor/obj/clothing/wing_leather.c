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
  SetKeyName("frogskin winglet");
  SetId(( {"winglet"} ));
  SetShort("a frogskin winglet");
  SetAdjectives( ({"frogskin"}) );
  SetLong(
    "A triangle of cured and treated frogskin, worn by a handful of sprites "
    "that value the integrity of their wings over the integrity of their "
    "fashion sense, social standing, or sense of smell. The thin rubbery "
    "still has a few warts on it, even--but it burns much slower than sprite "
    "wing."
  );
  SetArmourType(A_WING);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(2000);
  SetMass(15);
  SetMaterial("leather");
  SetRepairDifficulty(20);
  SetSize(SIZE_VERY_SMALL);
  SetValue(500);
  SetVendorType(VT_ARMOUR);
  SetWarmth(10);
  SetWear("A puff of swamp smelling air poofs out as you stretch the frogskin over your wing.");
}

