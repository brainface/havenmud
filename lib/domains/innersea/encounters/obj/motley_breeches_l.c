// sailor clothes
// mahk '12
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetShort("a large pair of motley breeches");
  SetId( ({ "breeches" }) );
  SetKeyName("breeches");
  SetAdjectives( ({ "large", "motley", "pair", "of"  }) );
  SetLong(
    "These loose breeches seem to be sewn from a questionably "
    "stylish mix of used sailcloth and stolen finery of a "
    "kaliedoscope of hues. They would offer some protection "
    "from the elements and basic modesty without impairing movement."
  );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_PANTS);
  SetDamagePoints(1200);
  SetMass(30);
  SetMaterials( ({ "textile" }) );
  SetSize(SIZE_LARGE);
  SetValue(0);
  SetWarmth(5);
}

