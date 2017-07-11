// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("tattered pants");
  SetShort("a pair of tattered pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "tattered", "pair", "of" }) );
  SetLong(
    "This pair of pants is torn and covered in dirt. Their only purpose "
    "seems to be keeping a person warm, if only slightly. They seem to "
    "be made from the hide of some animal, but are so old it is "
    "difficult to imagine which. "
  );
  SetMass(10);
  SetValue(0);
  SetDamagePoints(1000);
  SetWarmth(20);
  SetMaterial("textile");
  SetRepairDifficulty(85);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_PANTS);
}
