#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("breastplate");
  SetShort("a plate mail breastplate");
  SetId( ({ "breastplate" }) );
  SetAdjectives( ({ "mail","plate" }) );
  SetArmourType(A_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetLong("The metal breastplate appears to be extremely durable and would protect "
    "the wearer well. On the center of the breastplate a pair of coiling vipers are "
    "etched into the metal.");
  SetValue(1500);
  SetMass(150);
  SetDamagePoints(25000);
  SetArmourClass(ARMOUR_PLATE);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(85);
  SetWarmth(0);
  SetVendorType(VT_ARMOUR);
 }
