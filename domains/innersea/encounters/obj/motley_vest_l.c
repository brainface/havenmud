// sailor clothes
// mahk '12
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetShort("a large motley vest");
  SetId( ({ "vest" }) );
  SetKeyName("vest");
  SetAdjectives( ({ "large", "motley","vest"  }) );
  SetLong(
    "This loose vest is little more than draped sailcloth "
    "garnished with bits of mismatched silk finery. It offers "
    "some protection from the rain and is possibly one of the "
    "more stylish garments available in orcish sizes."
  );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_VEST);
  SetDamagePoints(1200);
  SetMass(30);
  SetMaterials( ({ "textile" }) );
  SetSize(SIZE_LARGE);
  SetValue(0);
  SetWarmth(5);
}


