// Zeratul@Haven
// For necro leader

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("bone armour");
  SetShort("a suit of bone armour");
  SetId( ({ "armour","armor","bone armour","bone armor" }) );
  SetAdjectives( ({ "bone" }) );
  SetLong(
     "This suit of armour has been crafted out of humanoid bones. Femures, ribs, "
     "and human skulls comprise this suit, giving it a very sinister and evil look. "
     "The human skulls sitting on the shoulder part of the armour have been stained "
     "red, as though blood has been dripped out of the eyes and dried. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(50);
  SetValue(600);
  SetDamagePoints(1200);
  SetSize(SIZE_MEDIUM);
  }
