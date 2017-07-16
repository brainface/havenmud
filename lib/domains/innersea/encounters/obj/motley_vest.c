// sailor clothes
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetShort("a motley vest");
  SetId( ({ "vest" }) );
  SetKeyName("vest");
  SetAdjectives( ({ "motley", "vest"  }) );
  SetLong(
    "This tight-fitting vest was sewn from a garrish mix-mash "
    "of different colored threads, and afterwards patched and "
    "repatched with even more hues. It provides only a token "
    "amount of modesty and spits in the very face of fashion."
  );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_VEST);
  SetDamagePoints(1200);
  SetMass(30);
  SetMaterials( ({ "textile" }) );
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  SetWarmth(5);
}

