// sailor clothes
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetShort("a motley pair of breeches");
  SetId( ({ "breeches" }) );
  SetKeyName("breeches");
  SetAdjectives( ({ "motley", "pair", "of"  }) );
  SetLong(
    "These tight-fitting breeches were sewn from a garrish mix-mash "
    "of different colored threads, and afterwards patched and "
    "repatched with even more hues. They would offer some protection "
    "from the elements and basic modesty without impairing movement."
  );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_PANTS);
  SetDamagePoints(1200);
  SetMass(30);
  SetMaterials( ({ "textile" }) );
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  SetWarmth(5);
}

