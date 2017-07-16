// haven ferry captain
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); 
  SetKeyName("jacket");
  SetShort("a uniform jacket");
  SetId( ({ "jacket" }) );
  SetAdjectives( ({ "uniform",  }) );
  SetLong(
    "This white linen jacket is marked with several diagonal lines "
    "along the arm, probably denoting rank. The waist and sleeve "
    "buttons are polished brass engraved with a dragon emblem."
  );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_CLOAK);
  SetDamagePoints(1200);
  SetMass(40);
  SetMaterials( ({ "textile" }) ); 
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  SetWarmth(10);
}


