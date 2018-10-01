//  Fancy Shirt for Clothier
//  Desc by Vaash - Alessandra 2009

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"handsome"}) );
  SetShort("a handsome shirt");
  SetLong(
     "This handsome shirt is made of a crisp white material. The sleeves "
     "are long and the cuffs are stiff and closed with the same pearl "
     "buttons that line the chest."
     );
  SetMass(20);
  SetWarmth(8);
  SetSize(SIZE_MEDIUM);
  SetValue(390);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetDamagePoints(90);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_SHIRT);

}


