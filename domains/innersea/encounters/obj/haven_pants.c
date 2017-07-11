
// haven ferry captain
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); 
  SetShort("a pair of white trousers");
  SetId( ({ "trousers" }) );
  SetKeyName("trousers");
  SetAdjectives( ({ "white", "pair", "of"  }) );
  SetLong(
    "These trousers are made of white linen. The legs "
    "flare out below the knee."
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

