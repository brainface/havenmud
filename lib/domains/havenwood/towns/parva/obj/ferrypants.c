// haven ferry captain
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); 
  SetShort("a pair of canvas breeches");
  SetId( ({ "breeches" }) );
  SetKeyName("breeches");
  SetAdjectives( ({ "canvas", "pair", "of"  }) );
  SetLong(
    "These canvas breeches are made of simple sailcloth dyed brown."
    " Brass buttons affix the fly. They stick of fish and brine,"
    " and probably haven't been cleaned in a while."
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

