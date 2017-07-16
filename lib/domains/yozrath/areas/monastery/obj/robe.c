// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("robe");
  SetShort("a white robe");
  SetId( ({"robe"}) );
  SetAdjectives( ({"white"}) );
  SetLong(
    "This white robe looks very warm. It seems both functional and "
    "attractive. It is white, with the symbol of the Kylin faith, a balance "
    "entwined with a red dragon, sewn on the front. It is somewhat dirty, "
    "suggesting that the wearer doesn't often remove it."
  );
  SetMass(50);
  SetValue(200);
  SetDamagePoints(750);
  SetWarmth(30);
  SetMaterial("textile");
  SetRepairDifficulty(15);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
}

/** Approved by Laoise at Sun May 21 17:03:17 2006. **/