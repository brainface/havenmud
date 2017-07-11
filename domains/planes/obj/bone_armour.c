/* Evil armour for bane devil */
// Mahkefel 10/2010: increased damage points to be 500 more than durgoroth shop item
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("bone armour");
  SetArmourType(A_ARMOUR);
  SetShort("a bloody suit of bone armour");
  SetLong(
    "This suit of armour was formed from the bones of the devil's victims. "
    "Ribcages from the torso, and heavy femurs line the arms. Nails and "
    "strips of leathered skin bind the bloody remains together. "
    );
SetDamagePoints(2500);
  SetId( ({ "suit", "bone", "armour" }) );
  SetAdjectives( ({ "bloody", "bone", "suit", "of", }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(300);
  SetMaterials( ({ "natural", "leather" }) );
  SetRepairDifficulty(40);
  SetSize(SIZE_LARGE);
  SetValue(2500);
  SetWarmth(0);
}
