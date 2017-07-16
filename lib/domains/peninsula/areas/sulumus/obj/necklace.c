// Proximo@Pax Imperialis
// 06/19/2003

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("necklace");
  SetId( ({ "necklace" }) );
  SetAdjectives( ({ "gold" }) );
  SetShort("a gold necklace");
  SetLong(
     "This necklace was made from a fine gold alloy. It's sizable amount "
     "of pure gold makes this item valuable, though unable to withstand harsh "
     "treatment. "
     );
  SetVendorType(VT_TREASURE);
  SetMass(35);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(60);
  SetArmourClass(ARMOUR_NATURAL);
  SetValue(250);
  SetDamagePoints(200);
  SetArmourType(A_AMULET);
}
